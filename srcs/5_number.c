/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:45:04 by dbrignon          #+#    #+#             */
/*   Updated: 2021/06/07 15:27:35 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	dim_list_a(t_world *all)
{
	t_a	*tmp;
	int	cont;

	cont = 0;
	tmp = *all->a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cont += 1;
	}
	return (cont);
}

void	order_stack_b(t_world *all)
{
	t_b	*aux;

	aux = *all->b;
	if (aux->val < aux->next->val)
		rotate_b(all);
}

int	check_second_minus_element(t_world *all, int min)
{
	t_a	*tmp;
	int	minore;

	tmp = *all->a;
	if (tmp->val == min)
		minore = tmp->next->val;
	else
		minore = tmp->val;
	while (tmp != NULL)
	{
		if (min != tmp->val && minore > tmp->val)
			minore = tmp->val;
		tmp = tmp->next;
	}
	return (minore);
}

void	sposta_num_stack_b(t_world *all)
{
	int	min;
	int	sec;
	t_a	*tmp;

	min = check_minus_element(all);
	sec = check_second_minus_element(all, min);
	tmp = *all->a;
	while (dim_list_a(all) != 3)
	{
		if (tmp->val == sec || tmp->val == min)
			push_b(all);
		else
			reverse_rotate_a(all);
		tmp = *all->a;
	}
	order_stack_b(all);
}

void	five_number_order(t_world *all)
{
	sposta_num_stack_b(all);
	tre_argomenti(all);
	push_a(all);
	push_a(all);
}
