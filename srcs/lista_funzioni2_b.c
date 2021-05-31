/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_funzioni2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:53:22 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/22 15:49:49 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_lista_b(t_world *all)
{
	t_b	*tmp;

	if (*all->b == NULL)
		printf("lista b vuota\n");
	else
	{
		tmp = *all->b;
		printf("LISTA B\n");
		printf("Puntatore inizio lista: %p\n", *all->b);
		while (tmp != NULL)
		{
			printf("\t%d\n", tmp->val);
			printf("\t%p\n", tmp->next);
			printf("\n\n");
			tmp = tmp->next;
		}
	}
}

void	delete_list_b(t_world *all)
{
	t_b	*tmp;

	if (*all->b == NULL)
		return ;
	while (*all->b != NULL)
	{
		tmp = (*all->b)->next;
		free(*all->b);
		*all->b = tmp;
	}
}
