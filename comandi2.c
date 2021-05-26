/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:54:37 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/26 08:02:49 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a_b(t_world *all)
{
	rotate_a(all);
	rotate_b(all);
}

void	reverse_rotate_a(t_world *all)
{
	int	val;

	val = delete(all);
	addnode(all, val);
}

void	reverse_rotate_b(t_world *all)
{
	int	val;

	val = delete_nodeb(all);
	addnodeb_ultimo(all, val);
}

void 	reverse_rotate_a_b(t_world *all)
{
	reverse_rotate_a(all);
	reverse_rotate_b(all);
}
