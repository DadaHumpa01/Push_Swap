/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:37:35 by dbrignon          #+#    #+#             */
/*   Updated: 2021/06/07 15:25:03 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	list_init(t_world *all)
{
	all->a = (t_a **)malloc(sizeof(t_a *));
	if (all->a == NULL)
		exit(1);
	*all->a = NULL;
	all->b = (t_b **)malloc(sizeof(t_b *));
	if (all->b == NULL)
		free_word(all);
	*all->b = NULL;
}

void	sotto_sequenza(t_world *all)
{
	set_index(all);
	check_value_index(all);
	check_value(all);
	while (*all->b != NULL)
	{
		check_pos(all);
		orchestatore_funzioni_effettive(all);
	}
	check_position_finale(all);
}

void	due_argomenti(t_world *all)
{
	t_a	*tmp;

	tmp = *all->a;
	if (tmp->val > tmp->next->val)
		rotate_a(all);
}

void	tre_argomenti(t_world *all)
{
	set_index(all);
	check_value_index(all);
	check_ott(all);
	order_3_number(all);
}

int	main(int ac, char **av)
{
	t_world	all;
	int		dim;

	list_init(&all);
	parsing(ac, av, &all);
	dim = dim_list_a_recursive(*all.a, 0);
	if (dim >= 5)
		sotto_sequenza(&all);
	else if (dim == 4)
		five_number_order(&all);
	else if (dim == 3)
		quattro_num(&all);
	else if (dim == 2)
		tre_argomenti(&all);
	else if (dim == 1)
		due_argomenti(&all);
	else if (dim == 0)
		exit (1);
	free_word(&all);
}
