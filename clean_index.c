/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:26:37 by danilo            #+#    #+#             */
/*   Updated: 2021/05/26 08:13:00 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_value_max_recursive(t_world *all, t_a *tmp)
{
	if (tmp->next == NULL)
		all->val_close_list = tmp->val;
	else
		check_value_max_recursive(all, tmp->next);
}

void	move_in_b_by_index(t_world *all, t_a *tmp)
{
	if (tmp->index >= 1)
		push_b(all);
	else
		reverse_rotate_a(all);
	new_list_recursive(all);
}

void	new_list_recursive(t_world *all)
{
	t_a *tmp;

	tmp = *all->a;
	if (tmp->val == all->val_close_list)
	{
		if (tmp->index >= 1)
			push_b(all);
		return ;
	}
	else
		move_in_b_by_index(all, tmp);
}

void	check_value(t_world *all)
{
	t_a	*tmp;

	tmp = *all->a;
	check_value_max_recursive(all, tmp);
	new_list_recursive(all);
}