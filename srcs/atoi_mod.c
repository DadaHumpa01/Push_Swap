/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:54:59 by dbrignon          #+#    #+#             */
/*   Updated: 2021/06/07 16:06:36 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_segno_inmezzo(char *str)
{
	int	i;
	int	car;

	i = 0;
	car = 0;
	while (str[i] != '\0' && str[i] != 32)
	{
		if (str[i] >= 48 && str[i] <= 57)
			car += 1;
		else if ((str[i] == 43 || str[i] == 45) && car != 0)
			error();
		i++;
	}
	return (1);
}

int	check_segno(char *str)
{
	int	i;
	int	meno;
	int	plus;

	plus = 0;
	meno = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != 32)
	{
		if (str[i] == 45)
			meno += 1;
		if (str[i] == 43)
			plus += 1;
		i++;
	}
	if (meno == 1 && plus == 0 && check_segno_inmezzo(str) == 1)
		return (1);
	else if (meno == 0 && plus == 0 && check_segno_inmezzo(str) == 1)
		return (0);
	else if (meno == 0 && plus == 1 && check_segno_inmezzo(str) == 1)
		return (0);
	error();
	return (-1);
}

int	Iatoi(char *str)
{
	int			i;
	long int	val;

	i = 0;
	val = 0;
	while (str[i] != '\0' && str[i] != 32)
	{
		if (str[i] >= 48 && str[i] <= 57)
			val = (val * 10) + (str[i] - '0');
		else if (str[i] != 43 && str[i] != 45)
			error();
		i++;
	}
	if (check_segno(str) == 1)
		val = val * -1;
	if (val >= -2147483648 && val < 2147483648)
		return (val);
	else
		error();
	return (val);
}
