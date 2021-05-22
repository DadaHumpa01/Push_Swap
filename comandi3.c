/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:31:10 by danilo            #+#    #+#             */
/*   Updated: 2021/05/22 09:38:44 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_world *all)
{
	int	tmp;

	tmp = (*all->a)->next->val;
	(*all->a)->next->val = (*all->a)->val;
	(*all->a)->val = tmp;
}

void	swap_b(t_world *all)
{
	int	tmp;

	tmp = (*all->b)->next->val;
	(*all->b)->next->val = (*all->b)->val;
	(*all->b)->val = tmp;
}