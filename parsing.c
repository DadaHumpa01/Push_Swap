/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:39:08 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/21 15:25:46 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error()
{
	printf("Error\n");
	exit(1);
}

int	Iatoi(char *str)
{
	long int val;
	int i;
	int meno;

	meno = 0;
	i = 0;
	val = 0;
	while (str[i] != '\0' && str[i] != 32)
	{
		if (str[i] == 45)
			meno += 1;
		else if (str[i] >= 48 && str[i] <= 57)
			val = val * 10 + (str[i] - '0');
		else if (str[i] != 43)
			error();
		i++;
	}
	if (meno % 2 != 0)
		error();
	return (val);
}

void check_spazzi(char *str)
{
	int i;
	int val;

	i = 0;
	if (str[i] == 0)
		error();
	if (str[i] != 32)
	{	
		val = Iatoi(&str[i]);
		printf("Itoa valore %d: \n", val);
	}
	while (str[i] != '\0')
	{
		if (str[i] == 32 && (str[i + 1] != 32 && str[i + 1] != '\0'))
		{
			val = Iatoi(&str[i + 1]);
			printf("Itoa valore %d: \n", val);
		}
		if (str[i] == 32 && str[i + 1] == '\0')
			error();
		i++;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	printf("%d\n", ac);
	if (ac > 1)
	{
		while (ac != i)
		{
			printf("argomento %d: %s\n",i, av[i]);
			check_spazzi(av[i]);
			i++;
		}
	}
	else
		printf("Error aggiungimi un argomento\n");
}