/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:53:40 by danilo            #+#    #+#             */
/*   Updated: 2021/05/27 20:54:16 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_pos_num_b(t_world *all, t_b *aux, int pos)
{
	if (aux == NULL)
		return;
	else
	{
		aux->pos_in_stack = pos;
		check_pos_num_b(all, aux->next, pos + 1);
	}
}

void	calculate_mosse(t_world *all, t_b *aux)
{
	if (aux == NULL)
		return ;
	else
	{
		aux->mosse = aux->pos_in_stack + aux->pos;
		calculate_mosse(all, aux->next);
	}
}

int	trova_numero_meno_mosse(t_b *aux, int num, int mosse)
{
	if (aux == NULL)
		return (num);
	else
	{
		if (aux->mosse < mosse)
			return (num = trova_numero_meno_mosse(aux->next, aux->val, aux->mosse));
		return (num = trova_numero_meno_mosse(aux->next, num, mosse));
	}
}

void	calculate_best_option(t_world *all, int num)
{
	t_b	*aux;
	int val;

	val = 0;
	val += 1;
	aux = *all->b;
	while (aux != NULL && aux->val != num)
		aux = aux->next;
	if (dim_list_b_recursive(*all->b, 0) - aux->pos_in_stack + 1 <= aux->pos_in_stack)
		all->rrb = dim_list_b_recursive(*all->b, 0) - aux->pos_in_stack + 1;
	else
		all->rb = aux->pos_in_stack;
	val = trova_pos_recursive(*all->a, aux->val, 0);
	if (dim_list_a_recursive(*all->a, 0) - aux->pos + 1 <= aux->pos)
			all->rra = dim_list_a_recursive(*all->a, 0) - aux->pos + 1;
	else
		all->ra = aux->pos;
}

int		trova_pos_recursive(t_a *tmp, int num, int pos)
{
	if (tmp->next == NULL)
		return (pos);
	else
	{
		if (tmp->val < num && tmp->next->val > num && tmp->next != NULL)
			return (pos + 1);
		return (pos = trova_pos_recursive(tmp->next, num, pos +1));
	}
}