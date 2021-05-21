/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_funzioni_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:55:26 by danilo            #+#    #+#             */
/*   Updated: 2021/05/21 18:04:23 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	addnodeb_davanti(t_world *all, int valore)
{
	t_b	*tmp;

	if (*all->b == NULL)
	{
		tmp = (t_b *)malloc(sizeof(t_a));
		tmp->val = valore;
		tmp->next = NULL;
		*all->b = tmp;
		return ;
	}
	tmp = *all->b;
	*all->b = (t_b *)malloc(sizeof(t_b));
	(*all->b)->next = tmp;
	(*all->b)->val = valore;
}

void	addnodeb_ultimo(t_world *all, int valore)
{
	t_b	*tmp;

	if (*all->b == NULL)
	{
		tmp = (t_b *)malloc(sizeof(t_a));
		if (tmp == NULL)
			exit(1);
		tmp->val = valore;
		tmp->next = NULL;
		*all->b = tmp;
		return ;
	}
	tmp = *all->b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_b *)malloc(sizeof(t_b));
	if (tmp == NULL)
		exit(1);
	tmp = tmp->next;
	tmp->val = valore;
	tmp->next = NULL;
}

int	delete_nodeb(t_world *all)
{
	t_b	*tmp;
	int	valore;

	if (*all->b == NULL)
		return (-1);
	tmp = (*all->b)->next;
	valore = (*all->b)->val;
	free(*all->b);
	*all->b = tmp;
	return (valore);
}

int	delete_ultimonodeb(t_world *all)
{
	t_b	*tmp;
	int	valore;

	if (*all->b == NULL)
		return (-1);
	tmp = *all->b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	valore = tmp->next->val;
	free(tmp->next);
	tmp->next = NULL;
	return (valore);
}
