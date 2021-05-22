/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:54:37 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/22 15:24:55 by dbrignon         ###   ########.fr       */
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
