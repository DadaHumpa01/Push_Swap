/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/27 09:26:29 by dbrignon         ###   ########.fr       */
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
			printf("| %-7d   |", tmp->val);
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