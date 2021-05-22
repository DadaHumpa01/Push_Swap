/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:39:08 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/22 15:56:50 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(void)
{
	printf("Error\n");
	exit(1);
}

void	check_spazzi(t_world *all, char *str)
{
	int	i;
	int	val;

	i = 0;
	if (str[i] != 32)
	{	
		val = Iatoi(&str[i]);
		printf("Itoa valore %d: \n", val);
		addnode(all, val);
	}
	while (str[i] != '\0')
	{
		if (str[i] == 32 && (str[i + 1] != 32 && str[i + 1] != '\0'))
		{
			val = Iatoi(&str[i + 1]);
			printf("Itoa valore %d: \n", val);
			addnode(all, val);
		}
		i++;
	}
}

void	check_str(t_world *all, char *str)
{
	int	i;
	int	car;

	car = 0;
	i = 0;
	if (str[i] == 0)
		error();
	while (str[i] != 0)
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] == 45 || str[i] == 43))
			car += 1;
		else if (car == 0 && (str[i + 1] != 32 && str[i + 1] == '\0'))
			error();
		if ((str[i] == 45 || str[i] == 43)
			&& (str[i + 1] == '\0' || str[i + 1] == 32))
			error();
		i++;
	}
	if (car == 0)
		error();
	check_spazzi(all, str);
}

void 	parsing(int ac, char **av, t_world *all)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (ac != i)
		{
			check_str(all, av[i]);
			i++;
		}
	}
	else
		error();
}
