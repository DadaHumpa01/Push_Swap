/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_funzioni_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:55:26 by danilo            #+#    #+#             */
/*   Updated: 2021/05/20 12:18:22 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	addnodeb_davanti(t_b **oi, int valore)
{
	t_b	*tmp;

	if (*oi == NULL)
	{
		tmp = (t_b *)malloc(sizeof(t_a));
		tmp->val = valore;
		tmp->next = NULL;
		*oi = tmp;
		return ;
	}
	tmp = *oi;
	*oi = (t_b *)malloc(sizeof(t_b));
	(*oi)->next = tmp;
	(*oi)->val = valore;
}
/*
void	addnodeb_ultimo(t_b **oi, int valore)
{
	t_b	*tmp;

	if (*oi == NULL)
	{
		tmp = (t_b *)malloc(sizeof(t_a));
		if (tmp == NULL)
			exit ;
		tmp->val = valore;
		tmp->next = NULL;
		*oi = tmp;
		return ;
	}
	tmp = *oi;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_b *)malloc(sizeof(t_b));
	if (tmp == NULL)
		exit ;
	tmp = tmp->next;
	tmp->val = valore;
	tmp->next = NULL;
}
*/
int	delete_nodeb(t_b **oi)
{
	t_b	*tmp;
	int	valore;

	if (*oi == NULL)
		return (-1);
	tmp = (*oi)->next;
	valore = (*oi)->val;
	free(*oi);
	*oi = tmp;
	return (valore);
}

int	delete_ultimonodeb(t_b **oi)
{
	t_b	*tmp;
	int	valore;

	if (*oi == NULL)
		return (-1);
	tmp = *oi;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	valore = tmp->val;
	free(tmp->next);
	tmp->next = NULL;
	return (valore);
}
