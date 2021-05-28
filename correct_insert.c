/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:09:19 by danilo            #+#    #+#             */
/*   Updated: 2021/05/27 21:33:15 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_pos_big_element(t_world *all, int num)
{
	t_a *tmp;
	int	cont;

	cont = 0;
	tmp = *all->a;
	while (tmp != NULL)
	{
		if (num == tmp->val)
			return (cont);
		cont += 1;
		tmp = tmp->next;
	}
	return (cont - 1);
}

int	check_big_element(t_world *all)
{
	t_a *tmp;
	int magiore;

	tmp = *all->a;
	while (tmp != NULL)
	{
		if (magiore < tmp->val)
			magiore = tmp->val;
		tmp = tmp->next;
	}
	return (magiore);
}

void	orchestratore(t_world *all)
{
	int	num;
	int pos;

	num = check_big_element(all);
	pos = check_pos_big_element(all, num);
	printf("pos elemento = %d\n", pos);
	printf("dimensione lista = %d\n", dim_list_a_recursive(*all->a, 0));
	if (dim_list_a_recursive(*all->a, 0) == pos)
		printf("l'elemento più grande è ultimo\n");
	else
		printf("l'elemento non è l'ultimo");
}