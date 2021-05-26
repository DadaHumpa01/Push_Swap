/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:37:35 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/25 21:54:06 by danilo           ###   ########.fr       */
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
	all->mosse = 0;
}

int	main(int ac, char **av)
{
	t_world	all;
	int	indice;

	list_init(&all);
	parsing(ac, av, &all);
	set_index(&all);
	printlist(&all);
	check_value_index(&all);
	printlist(&all);
	//printf("\n Ultimo valore dello stack a = %d\n", check_list_a_ultimo(&all));
	check_value(&all);
	printlist(&all);
}
