/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/24 16:54:05 by dbrignon         ###   ########.fr       */
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
			printf(" %-7d|\n", aux->val);
			aux = aux->next;
		}
		else
			printf("           |\n");
	}
	printf("\\-----------------------/\n");
	return ;
}

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

int	dim_list_a(t_world *all)
{
	int	dim;
	t_a	*tmp;

	dim = 0;
	tmp = *all->a;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		dim += 1;
		tmp = (tmp)->next;
	}
	return (dim);
}
