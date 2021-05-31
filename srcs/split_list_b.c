/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:39:41 by danilo            #+#    #+#             */
/*   Updated: 2021/05/31 11:56:48 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	delete_element_by_list(t_world *all, int delete)
{
	t_a	*tmp;
	t_a	*aux;

	tmp = *all->a;
	aux = *all->a;
	while (tmp != NULL)
	{
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
