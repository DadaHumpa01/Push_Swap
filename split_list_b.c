/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:39:41 by danilo            #+#    #+#             */
/*   Updated: 2021/05/24 21:13:44 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	delete_element_by_list(t_world *all, int delete)
{
	t_a *tmp;
	t_a *aux;

	tmp = *all->a;
	aux = *all->a;
	while (tmp != NULL)
	{
		// if(tmp->next->next == NULL)
		// {
		// 	free(tmp->next);
		// 	tmp->next = NULL;
		// }
		if (tmp->next->val == delete)
		{
			printf("%p\n", aux);
			tmp = tmp->next;
			printf("%p\n", tmp);
			free(tmp->next);
			tmp = aux->next;
		}
		tmp = tmp->next;
		aux = aux->next;
	}
}

void	split_list_a(t_world *all)
{
	t_a	*tmp;

	tmp = *all->a;
	while (tmp != NULL)
	{
		if (tmp->index >= 1)
		{
			addnodeb_davanti(all, tmp->val);
			delete_element_by_list(all, tmp->val);
		}
		tmp = tmp->next;
	}
}

//72 30 97 95 -94 -73 -79 3 63 -16 11 -28 22 47 -39 -64 20 87 6  45 -82 -50 52 -66 92 6 7 -8379 -80 -7