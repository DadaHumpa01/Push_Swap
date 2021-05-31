/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:52:11 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/31 11:52:23 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	printlist(t_world *all)
{
	printf("/-----------------------\\\n");
	printf("|  Lista A  |  Lista B  |\n");
	printf("|-----------|-----------|\n");
	t_a *tmp;
	t_b *aux;

	tmp = *all->a;
	aux = *all->b;
	while (tmp != NULL || aux != NULL)
	{
		if (tmp != NULL)
		{
			printf("| %-7d %d |", tmp->val, tmp->index);
			tmp = tmp->next;
		}
		else
			printf("|           |");
		if (aux != NULL)
		{
			printf(" %-7d %d %d %d|\n", aux->val, aux->pos, aux->pos_in_stack, aux->mosse);
			aux = aux->next;
		}
		else
			printf("           |\n");
	}
	printf("\\-----------------------/\n");
	return ;
}
