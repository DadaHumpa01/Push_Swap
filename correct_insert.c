/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:09:19 by danilo            #+#    #+#             */
/*   Updated: 2021/05/28 17:48:32 by dbrignon         ###   ########.fr       */
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
	return (cont);
}

int	check_pos_minus_element(t_world *all, int num)
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
	return (cont);
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

int	check_minus_element(t_world *all)
{
	t_a *tmp;
	int minore;

	tmp = *all->a;
	while (tmp != NULL)
	{
		if (minore > tmp->val)
			minore = tmp->val;
		tmp = tmp->next;
	}
	return (minore);
}

int	trova_pos(t_world *all, int num)
{
	t_a	*tmp;
	int	pos;

	pos = 0;
	tmp = *all->a;
	if (num < check_minus_element(all))
	{
		printf("qui cé il bug %d\n", check_pos_minus_element(all, check_minus_element(all)) - 1);
		printf("dimensione lista %d\n", dim_list_a_recursive(*all->a, 0));
		return (check_pos_minus_element(all, check_minus_element(all)));
	}
	if (num > check_big_element(all))
		return (check_pos_big_element(all, check_big_element(all)) + 1);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->val < num && tmp->next->val > num)
		{
			return (pos + 1);
		}
		pos += 1;
		tmp = tmp->next;
	}
	return (pos + 1);
}