/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:18:32 by danilo            #+#    #+#             */
/*   Updated: 2021/06/07 15:26:19 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	order_3_number(t_world *all)
{
	t_a	*tmp;

	tmp = *all->a;
	if (tmp->index == -1 && tmp->next->index == -2
		&& tmp->next->next->index == -3)
		return ;
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

void	check_ott(t_world *all)
{
	t_a	*tmp;
	int	minus;
	int	val;

	val = numero_mag_in_sott(all);
	minus = 0;
	tmp = *all->a;
	while (tmp != NULL)
	{
		if (tmp->index < 0)
			minus = 1;
		if (tmp->val > val && minus == 0)
		{
			tmp->index = -1;
			val = tmp->val;
		}
		tmp = tmp->next;
	}
}
