/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:18:32 by danilo            #+#    #+#             */
/*   Updated: 2021/05/31 09:36:01 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	order_3_number(t_world *all)
{
	t_a  *tmp;
	
	tmp = *all->a;
	if (tmp->next->next->index == -3)
		printf("non devo fare nulla\n");
	else if (tmp->index == 1 && tmp->next->index >= -1)
		swap_a(all);
	else if (tmp->index == -1 && tmp->next->next->index == -1)
	{
		swap_a(all);
		rotate_a(all);
	}
	else if (tmp->index == -1 && tmp->next->index == -1)
		reverse_rotate_a(all);
	else if (tmp->index == -1 && tmp->next->next->index == -2)
	{
		swap_a(all);
		reverse_rotate_a(all);
	}
	else if (tmp->index == -1 && tmp->next->index == -2)
		rotate_a(all);
}