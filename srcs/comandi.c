/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:49:10 by danilo            #+#    #+#             */
/*   Updated: 2021/05/30 19:20:57 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_world *all)
{
	if (*all->b == NULL)
		return ;
	addnodedavanti(all, (*all->b)->val);
	delete_nodeb(all);
	write(1, "pa\n ", 3);
}

void	push_b(t_world *all)
{
	if (*all->a == NULL)
		return ;
	addnodeb_davanti(all, (*all->a)->val);
	delete(all);
	write(1, "pb\n ", 3);
}

void	rotate_a(t_world *all)
{
	int	val;

	val = delete_ultimo(all);
	addnodedavanti(all, val);
	write(1, "rra\n ", 4);
}

void	rotate_b(t_world *all)
{
	int	val;

	val = delete_ultimonodeb(all);
	addnodeb_davanti(all, val);
	write(1, "rrb\n ", 4);
}

void	free_word(t_world *all)
{
	if (*all->a != NULL)
		delete_list_a(all);
	free(all->a);
	if (*all->b != NULL)
		delete_list_b(all);
	free(all->b);
}
