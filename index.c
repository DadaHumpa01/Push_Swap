/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:46 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/24 18:27:21 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_index_minus(t_world *all, int num)
{
	t_a	*tmp;

	tmp = *all->a;
	while (tmp != NULL)
	{
		if (tmp->val == num)
			tmp->index *= -1;
		tmp = tmp->next;
	}
}

void	recursive_index(t_world *all, int indice)
{
	t_a	*tmp;
	int	savenum;

	savenum = 0;
	while (indice != 0)
	{
		tmp = *all->a;
		while (tmp != NULL)
		{
			if (tmp->index == ((indice * -1) - 1))
				break;
			if (tmp->index == indice)
				savenum = tmp->val;
			tmp = tmp->next;
		}
		set_index_minus(all, savenum);
		indice -= 1;
	}
}

int	set_index_by_num(t_world *all, int val, int index)
{
	t_a	*tmp;
	int	indice;

	indice = 1;
	tmp = *all->a;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			break;
		if (tmp->index > indice)
			indice = tmp->index;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp->val > val && tmp->val != val && tmp->index == index)
			tmp->index += 1;
		if (tmp->index > indice)
			indice = tmp->index;
		tmp = tmp->next;
	}
	return (indice);
}

void	check_value_index(t_world *all)
{
	t_a	*tmp;
	int	indice;

	tmp = *all->a;
	while (tmp != NULL)
	{
		indice = set_index_by_num(all, tmp->val, tmp->index);
		tmp = tmp->next;
	}
	recursive_index(all, indice);
}

void	set_index(t_world *all)
{
	t_a *tmp;

	tmp = *all->a;
	while (tmp != NULL)
	{
		tmp->index = 1;
		tmp = tmp->next;
	}
}