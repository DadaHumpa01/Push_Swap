/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_funzioni2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:53:22 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/21 17:33:33 by dbrignon         ###   ########.fr       */
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
