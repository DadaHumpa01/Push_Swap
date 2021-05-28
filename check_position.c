/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:17:34 by danilo            #+#    #+#             */
/*   Updated: 2021/05/28 17:51:19 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_pos_list(t_world *all, t_b *tmp)
{
	t_a *aux;

	aux = *all->a;
	if (tmp->next == NULL)
	{
		tmp->pos = trova_pos(all, tmp->val);
		if (tmp->pos == dim_list_a_recursive(*all->a, 0) + 1)
			tmp->pos = 0;
		return ;
	}
	else
	{	
		tmp->pos = trova_pos(all, tmp->val);
		if (tmp->pos == dim_list_a_recursive(*all->a, 0) + 1)
			tmp->pos = 0;
		printf("valore tmp pos %d per il numero %d\n", tmp->pos, tmp->val);
		assign_pos_list(all, tmp->next);
	}
}

int	dim_list_b_recursive(t_b *aux, int cont)
{
	if (aux->next == NULL)
		return (cont);
	else
		return (cont = dim_list_b_recursive(aux->next, cont + 1));
}

void	check_minus_mosse_a(t_world *all)
{
	t_b *aux;

	aux = *all->b;
	while (aux != NULL)
	{
		if (dim_list_a_recursive(*all->a, 0) - aux->pos + 1 <= aux->pos)
			aux->pos = dim_list_a_recursive(*all->a, 0) - aux->pos + 1;
		else
			aux->pos = aux->pos;
		aux = aux->next;
	}
}

void	check_minus_mosse_b(t_world *all)
{
	t_b *aux;

	aux = *all->b;
	while (aux != NULL)
	{
		if (dim_list_b_recursive(*all->b, 0) - aux->pos_in_stack + 1 <= aux->pos_in_stack)
			aux->pos_in_stack = dim_list_b_recursive(*all->b, 0) - aux->pos_in_stack + 1;
		else
			aux->pos_in_stack = aux->pos_in_stack;
		aux = aux->next;
	}
}

void	check_pos(t_world *all)
{
	init_moss(all);
	assign_pos_list(all, *all->b);
	check_pos_num_b(all, *all->b, 0);
	check_minus_mosse_a(all);
	check_minus_mosse_b(all);
	calculate_mosse(all, *all->b);
	assign_pos_list(all, *all->b);
	check_pos_num_b(all, *all->b, 0);
	calculate_best_option(all, trova_numero_meno_mosse(*all->b, 0, 2147483647));
}