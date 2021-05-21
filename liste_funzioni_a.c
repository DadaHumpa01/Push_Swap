/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/21 17:34:41 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	printlist(t_world *all)
{
 	print_lista_a(all);
 	print_lista_b(all);
}

void	addnodedavanti(t_world *all, int val)
{
	printf("ciao\n");
	t_a *tmp;

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
