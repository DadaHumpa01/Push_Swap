/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_number.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:20:50 by dbrignon          #+#    #+#             */
/*   Updated: 2021/06/07 15:27:35 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sposta_num(t_world *all)
{
	int	min;
	t_a	*tmp;

	tmp = *all->a;
	min = check_minus_element(all);
	while (dim_list_a(all) != 3)
	{
		if (tmp->val == min)
			push_b(all);
		else
			reverse_rotate_a(all);
		tmp = *all->a;
	}
}

void	quattro_num(t_world *all)
{
	sposta_num(all);
	tre_argomenti(all);
	push_a(all);
}
