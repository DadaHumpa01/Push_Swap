/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:54:37 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/28 14:34:53 by dbrignon         ###   ########.fr       */
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
	printf("rrr\n");
}

void	reverse_rotate_a(t_world *all)
{
	int	val;

	val = delete(all);
	addnode(all, val);
	printf("ra\n");
	all->mosse += 1;
}

void	reverse_rotate_b(t_world *all)
{
	int	val;

	val = delete_nodeb(all);
	addnodeb_ultimo(all, val);
	printf("rb\n");
	all->mosse += 1;
}

void 	reverse_rotate_a_b(t_world *all)
{
	int	val;

	val = delete(all);
	addnode(all, val);
	val = delete_nodeb(all);
	addnodeb_ultimo(all, val);
	printf("rr\n");
}
