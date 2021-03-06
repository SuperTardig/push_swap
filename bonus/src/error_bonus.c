/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:42:48 by bperron           #+#    #+#             */
/*   Updated: 2022/06/23 10:23:22 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	checkmax(int ac, char *av[])
{
	long long	j;
	int			i;

	i = 1;
	while (i < ac)
	{
		j = ft_atoll(av[i]);
		if (j > INT_MAX || j < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	checkdup(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j++ < ac - 1)
		{
			if (i != j)
			{
				if (ft_strcmp(av[i], av[j]) == 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	checkint(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9' )
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error(int ac, char *av[])
{
	if (checkint(ac, av) == 1 || checkdup(ac, av) == 1
		|| checkmax(ac, av) == 1)
		return (1);
	return (0);
}
