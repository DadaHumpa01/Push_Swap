/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:26:37 by danilo            #+#    #+#             */
/*   Updated: 2021/05/31 11:49:24 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	numero_mag_in_sott(t_world *all)
{
	t_a		*tmp;
	long	num;
	int		index;

	index = 0;
	tmp = *all->a;
	num = -2147483649;
	while (tmp != NULL)
	{
		if (tmp->val > num && tmp->index < index)
		{	
			index = tmp->index;
			num = tmp->val;
		}
		tmp = tmp->next;
	}
	return (num);
}

void	check_value_max_recursive(t_world *all, t_a *tmp)
{
	if (tmp->next == NULL)
		all->val_close_list = tmp->val;
	else
		check_value_max_recursive(all, tmp->next);
}

void	move_in_b_by_index(t_world *all, t_a *tmp, int num, int minus)
{
	if (tmp->index < 0)
		reverse_rotate_a(all);
	else
		push_b(all);
	new_list_recursive(all, num, minus);
}

void	new_list_recursive(t_world *all, int num, int minus)
{
	t_a	*tmp;

	tmp = *all->a;
	if (tmp->val == all->val_close_list)
	{
		if (tmp->index >= 1)
			push_b(all);
		return ;
	}
	else
		move_in_b_by_index(all, tmp, num, minus);
}

void	check_value(t_world *all)
{
	t_a	*tmp;
	int	num;

	tmp = *all->a;
	num = numero_mag_in_sott(all);
	check_value_max_recursive(all, tmp);
	check_ott(all);
	new_list_recursive(all, num, 0);
}
