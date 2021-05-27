/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:17:34 by danilo            #+#    #+#             */
/*   Updated: 2021/05/26 22:04:41 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pos_num_mag(t_world *all, t_a *tmp, int num, int cont)
{
	if (tmp->val > num || tmp->next == NULL)
		return (cont);
	else
		return (cont = pos_num_mag(all, tmp->next, num, cont + 1));	
}

void	assign_pos_list(t_world *all, t_b *tmp)
{
	t_a *aux;

	aux = *all->a;
	if (tmp->next == NULL)
	{
		tmp->pos = pos_num_mag(all, aux, tmp->val, 0);
		return ;
	}
	else
	{	
		tmp->pos = pos_num_mag(all, aux, tmp->val, 0);
		assign_pos_list(all, tmp->next);
	}
}

void	calcolo_mosse(t_world *all)
{
	t_b *aux;
//	t_a *tmp;

//	tmp = *all->a;
	aux = *all->b;
	while (aux != NULL)
	{
		printf("per il numero: %d\n", aux->val);
		printf("\tbisogna fare %d ra \n", aux->pos);
		printf("\tbisogna fare %d rra\n", dim_list_a_recursive(*all->a, 0) - aux->pos + 1);
		aux = aux->next;
	}
}

void	check_pos(t_world *all)
{
	assign_pos_list(all, *all->b);
	check_pos_num_b(all, *all->b, 0);
	calcolo_mosse(all);
}