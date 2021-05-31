/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:31:10 by danilo            #+#    #+#             */
/*   Updated: 2021/05/31 11:38:57 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_world *all)
{
	int	tmp;

	tmp = (*all->a)->next->val;
	(*all->a)->next->val = (*all->a)->val;
	(*all->a)->val = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_world *all)
{
	int	tmp;

	tmp = (*all->b)->next->val;
	(*all->b)->next->val = (*all->b)->val;
	(*all->b)->val = tmp;
	write(1, "sb\n", 3);
}

void	swap_a_b(t_world *all)
{
	int	tmp;

	tmp = (*all->b)->next->val;
	(*all->b)->next->val = (*all->b)->val;
	(*all->b)->val = tmp;
	tmp = (*all->a)->next->val;
	(*all->a)->next->val = (*all->a)->val;
	(*all->a)->val = tmp;
	write(1, "ss\n", 3);
}
