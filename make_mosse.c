/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mosse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:32:48 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/28 15:12:02 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ottimizzazione_mosse(t_world *all)
{
	while ((all->ra != 0 && all->rb != 0) && (all->ra != -1 && all->rb != -1))
	{
		all->ra -= 1;
		all->rb -= 1;
		all->rr += 1;
	}
	while ((all->rra != 0 && all->rrb != 0) && (all->rra != -1 && all->rrb != -1))
	{
		all->rra -= 1;
		all->rrb -= 1;
		all->rrr += 1;
	}
}

void	make_me_move(t_world *all)
{
	while(all->ra != 0 && all->ra != -1)
	{
		reverse_rotate_a(all);
		all->ra -= 1;
	}
	while(all->rb != 0 && all->rb != -1)
	{
		reverse_rotate_b(all);
		all->rb -= 1;
	}
	while(all->rra != 0 && all->rra != -1)
	{
		rotate_a(all);
		all->rra -= 1;
	}
	while(all->rrb != 0 && all->rrb != -1)
	{
		rotate_b(all);
		all->rrb -= 1;
	}
}

void	make_me_move_ottimizzato(t_world *all)
{
	while(all->rr != 0 && all->rr != -1)
	{
		reverse_rotate_a_b(all);
		all->rr -= 1;
	}
	while(all->rrr != 0 && all->rrr != -1)
	{
		rotate_a_b(all);
		all->rrr -= 1;
	}
}

void	orchestatore_funzioni_effettive(t_world *all)
{
	ottimizzazione_mosse(all);
	make_me_move_ottimizzato(all);
	make_me_move(all);
	push_a(all);
}

void	init_moss(t_world *all)
{
	all->ra = -1;
	all->rb = -1;
	all->rra = -1;
	all->rrb = -1;
	all->rr = 0;
	all->rrr = 0;
}