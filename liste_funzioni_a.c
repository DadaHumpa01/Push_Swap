/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/19 10:08:56 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	printlist(t_a **ciao, t_b **oi)
{
	print_lista_a(ciao);
	print_lista_b(oi);
}

void	addnodedavanti(t_a **ciao, int val)
{
	t_a	*tmp;

	if (*ciao == NULL)
	{
		tmp = (t_a *)malloc(sizeof(t_a));
		tmp->val = val;
		tmp->next = NULL;
		*ciao = tmp;
		return ;
	}
	tmp = *ciao;
	*ciao = malloc(sizeof(t_a));
	(*ciao)->next = tmp;
	(*ciao)->val = val;
}

void	addnode(t_a **ciao, int val)
{
	t_a	*tmp;

	if (*ciao == NULL)
	{
		tmp = (t_a *)malloc(sizeof(t_a));
		tmp->val = val;
		tmp->next = NULL;
		*ciao = tmp;
		return ;
	}
	tmp = *ciao;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_a *)malloc(sizeof(t_a));
	tmp = tmp->next;
	tmp->val = val;
	tmp->next = NULL;
}

int	delete(t_a **ciao)
{
	t_a	*tmp;
	int	valore;

	if (*ciao == NULL)
		return (-1);
	tmp = (*ciao)->next;
	valore = (*ciao)->val;
	free(*ciao);
	*ciao = tmp;
	return (valore);
}
