/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:37:35 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/28 17:37:24 by dbrignon         ###   ########.fr       */
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
	char a;

	list_init(&all);
	parsing(ac, av, &all);
	set_index(&all);
	check_value_index(&all);
	check_value(&all);
	printlist(&all);
	while (*all.b != NULL)
	{
		scanf("%c", &a);
		if (a == 10)
		{
			check_pos(&all);
			orchestatore_funzioni_effettive(&all);
			printlist(&all);
		}
	}
	//ordine_finale_lista(&all);
	//printf("elemento piú piccolo %d\n", check_minus_element(&all));
	//printlist(&all);
	// printf("posizone trovata al numero %d\n", trova_pos(&all, 1155));
	//orchestratore(&all);
	//printf("posizione numero :%d\n", trova_pos_recursive(*all.a, -20543, 0));
	//printf("elemento all'interno della lista %d\n", dim_list_b_recursive(*all.b, 0));
	//printf("numero meno mosse: %d\n", trova_numero_meno_mosse(*all.b, 0, 2147483647));
}
