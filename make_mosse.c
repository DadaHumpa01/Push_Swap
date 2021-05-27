/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mosse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:32:48 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/27 17:52:22 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	make_me_move(t_world *all)
{
	while(all->ra != 0 && all->ra != -1)
	{
		rotate_a(all);
		all->ra -= 1;
	}
	while(all->rb != 0 && all->rb != -1)
	{
		rotate_b(all);
		all->rb -= 1;
	}
	while(all->rra != 0 && all->rra != -1)
	{
		reverse_rotate_a(all);
		all->rra -= 1;
	}
	while(all->rrb != 0 && all->rrb != -1)
	{
		reverse_rotate_a(all);
		all->rrb -= 1;
	}
	push_a(all);
}

void	init_moss(t_world *all)
{
	all->ra = -1;
	all->rb = -1;
	all->rra = -1;
	all->rrb = -1;
}