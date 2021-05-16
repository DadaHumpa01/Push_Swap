/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:45:42 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/16 18:32:24 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	printlist(t_a **ciao, t_b **oi)
{
	if (*ciao == NULL)
		printf("lista a vouta\n");
	else
	{
		t_a *tmp;
		tmp = *ciao;
		printf("LISTA A\n");
		printf("Puntatore inizio lista: %p\n", ciao);
		while (tmp != NULL)
		{
			printf("\t%d\n", tmp->val);
			printf("\t%p\n", tmp->next);
			printf("\n\n");
			tmp = tmp->next;
		}
	}
    if (*oi == NULL)
        printf("lista b vuota\n");
    else
    {
    	t_b *tmp;
		tmp = *oi;
		printf("LISTA B\n");
		printf("Puntatore inizio lista: %p\n", *oi);
		while (tmp != NULL)
		{
			printf("\t%d\n", tmp->val);
			printf("\t%p\n", tmp->next);
			printf("\n\n");
			tmp = tmp->next;
		}
    }
}

void	addnodedavanti(t_a **ciao, int val)
{
	t_a *tmp;

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
	t_a *tmp;

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

int		delete(t_a **ciao)
{
	t_a *tmp;
	int valore;

	if (*ciao == NULL)
		return (-1);
	tmp = (*ciao)->next;
	valore = (*ciao)->val;
	free(*ciao);
	*ciao = tmp;
	return(valore);
}
