/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:53:23 by bperron           #+#    #+#             */
/*   Updated: 2022/07/12 10:26:22 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include <stdio.h>

void	clean(t_stacks *stacks, char ***split)
{
	int			i;

	i = 1;
	cleanstacks(stacks);
	if (split)
	{
		if (*split)
		{
			while (split[0][i])
			{
				free(split[0][i]);
				i++;
			}
			if (split)
				free(*split);
		}
	}
}

void	cleanstacks(t_stacks *stacks)
{
	t_intlist	*tmp;

	if (stacks)
	{
		if (stacks->stack_a)
		{
			stacks->stack_a = returntop(stacks->stack_a);
			while (stacks->stack_a)
			{
				tmp = stacks->stack_a->next;
				free(stacks->stack_a);
				stacks->stack_a = tmp;
			}
		}
		if (stacks->stack_b)
		{
			while (stacks->stack_b)
			{
				tmp = stacks->stack_b->next;
				free(stacks->stack_b);
				stacks->stack_b = tmp;
			}
		}
	}
}

void	format2(t_stacks *stacks, char *output)
{
	if (ft_strcmp(output, "ss\n") == 0)
		ss(stacks);
	else if (ft_strcmp(output, "rr\n") == 0)
		rr(stacks);
	else if (ft_strcmp(output, "rrr\n") == 0)
		rrr(stacks);
}

void	format(t_stacks *stacks, char *output)
{
	if (ft_strcmp(output, "sa\n") == 0)
		sab(stacks->stack_a);
	else if (ft_strcmp(output, "sb\n") == 0)
		sab(stacks->stack_b);
	else if (ft_strcmp(output, "ra\n") == 0)
		rab(stacks->stack_a);
	else if (ft_strcmp(output, "rb\n") == 0)
		rab(stacks->stack_b);
	else if (ft_strcmp(output, "rra\n") == 0)
		rrab(stacks->stack_a);
	else if (ft_strcmp(output, "rrb\n") == 0)
		rrab(stacks->stack_b);
	else if (ft_strcmp(output, "pa\n") == 0)
		pab(stacks, 2);
	else if (ft_strcmp(output, "pb\n") == 0)
		pab(stacks, 1);
	else if (ft_strcmp(output, "bad") == 0)
		quit(stacks, output);
	format2(stacks, output);
	if (stacks->stack_a)
		stacks->stack_a = returntop(stacks->stack_a);
	if ((stacks->stack_b))
		stacks->stack_b = returntop(stacks->stack_b);
}

void	quit(t_stacks *stacks, char *output)
{
	ft_printf("Error\n");
	clean(stacks, NULL);
	(void) output;
	exit (0);
}
