/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/31 11:53:21 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	addnodedavanti(t_world *all, int val)
{
	t_a	*tmp;

	if (*all->a == NULL)
	{
		tmp = (t_a *)malloc(sizeof(t_a));
		tmp->val = val;
		tmp->next = NULL;
		*all->a = tmp;
		return ;
	}
	tmp = *all->a;
	*all->a = malloc(sizeof(t_a));
	(*all->a)->next = tmp;
	(*all->a)->val = val;
}

void	addnode(t_world *all, int val)
{
	t_a	*tmp;

	if (*all->a == NULL)
	{
		tmp = (t_a *)malloc(sizeof(t_a));
		tmp->val = val;
		tmp->next = NULL;
		*all->a = tmp;
		return ;
	}
	tmp = *all->a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_a *)malloc(sizeof(t_a));
	tmp = tmp->next;
	tmp->val = val;
	tmp->next = NULL;
}

int	delete(t_world *all)
{
	t_a	*tmp;
	int	valore;

	if (*all->a == NULL)
		return (-1);
	tmp = (*all->a)->next;
	valore = (*all->a)->val;
	free(*all->a);
	*all->a = tmp;
	return (valore);
}

int	dim_list_a_recursive(t_a *tmp, int cont)
{
	if (tmp->next == NULL)
		return (cont);
	else
		return (cont = dim_list_a_recursive(tmp->next, cont + 1));
}
