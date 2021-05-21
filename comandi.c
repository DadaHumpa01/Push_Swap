/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:49:10 by danilo            #+#    #+#             */
/*   Updated: 2021/05/21 17:51:56 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_world *all)
{
	if (*all->b == NULL)
		return ;
	addnodedavanti(all, (*all->b)->val);
	delete_nodeb(all);
}

void	push_b(t_world *all)
{
	if (*all->a == NULL)
		return ;
	addnodeb_davanti(all, (*all->a)->val);
	delete(all);
}

void	rotate_a(t_world *all)
{
	int val;

	val = delete_ultimo(all);
	addnodedavanti(all, val);
}

void	rotate_b(t_world *all)
{
	int val;

	val = delete_ultimonodeb(all);
	addnodeb_davanti(all, val);
}

void	free_word(t_world *all)
{
	return ;
}
