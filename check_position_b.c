/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:53:40 by danilo            #+#    #+#             */
/*   Updated: 2021/05/26 22:05:45 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_pos_num_b(t_world *all, t_b *aux, int pos)
{
	printf("ciclo");
	if (aux == NULL)
	{
		aux->pos_in_stack = pos;
		return ;
	}
	else
	{
		aux->pos_in_stack = pos;
		check_pos_num_b(all, aux->next, pos + 1);
	}
}

