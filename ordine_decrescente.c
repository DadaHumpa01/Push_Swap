/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordine_decrescente.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:57:26 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/28 17:31:45 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sistemare_la_lista_finale(t_world *all, int num)
{
	while (num != 0)
	{
		reverse_rotate_a(all);
		num--;
	}
}

void	sistemare_la_lista_finale_rra(t_world *all, int num)
{
	while (num != 0)
	{
		rotate_a(all);
		num++;
	}
}

void	check_position_finale(t_world *all)
{
	int	divisione;
	int	pos_ele_pc;
	int	dim_list;

	dim_list = dim_list_a_recursive(*all->a, 0);
	pos_ele_pc = check_pos_minus_element(all, check_minus_element(all));
	divisione = dim_list / 2;
	if (pos_ele_pc > divisione + 1)
		sistemare_la_lista_finale_rra(all, pos_ele_pc - dim_list);
	else
		sistemare_la_lista_finale(all, pos_ele_pc);

}
void	ordine_finale_lista(t_world *all)
{
	check_position_finale(all);
}