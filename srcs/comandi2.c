/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:54:37 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/30 19:20:57 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a_b(t_world *all)
{
	int	val;

	val = delete_ultimo(all);
	addnodedavanti(all, val);
	val = delete_ultimonodeb(all);
	addnodeb_davanti(all, val);
	write(1, "rrr\n ", 4);
}

void	reverse_rotate_a(t_world *all)
{
	int	val;

	val = delete(all);
	addnode(all, val);
	write(1, "ra\n ", 3);
	all->mosse += 1;
}

void	reverse_rotate_b(t_world *all)
{
	int	val;

	val = delete_nodeb(all);
	addnodeb_ultimo(all, val);
	write(1, "rb\n ", 3);
	all->mosse += 1;
}

void 	reverse_rotate_a_b(t_world *all)
{
	int	val;

	val = delete(all);
	addnode(all, val);
	val = delete_nodeb(all);
	addnodeb_ultimo(all, val);
	write(1, "rr\n ", 3);
}
