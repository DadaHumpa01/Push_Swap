/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni2_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:51:18 by danilo            #+#    #+#             */
/*   Updated: 2021/05/22 16:14:39 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	delete_ultimo(t_world *all)
{
	t_a		*tmp;
	int		valore;

	if (*all->a == NULL)
		return (-1);
	tmp = *all->a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	valore = tmp->next->val;
	free(tmp->next);
	tmp->next = NULL;
	return (valore);
}

void	delete_list_a(t_world *all)
{
	t_a	*tmp;

	if (*all->a == NULL)
		return ;
	while (*all->a != NULL)
	{
		tmp = (*all->a)->next;
		free(*all->a);
		*all->a = tmp;
	}
}

int	ricerca_valore(t_world *all, int domanda)
{
	t_a	*tmp;

	if (*all->a == NULL)
		return (0);
	tmp = *all->a;
	while (tmp->next != NULL)
	{
		if (tmp->val == domanda)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_lista_a(t_world *all)
{
	t_a	*tmp;

	if (*all->a == NULL)
		printf("lista a vouta\n");
	else
	{
		tmp = *all->a;
		printf("LISTA A\n");
		printf("Puntatore inizio lista: %p\n", all->a);
		while (tmp != NULL)
		{
			printf("\t%d\n", tmp->val);
			printf("\t%p\n", tmp->next);
			printf("\n\n");
			tmp = tmp->next;
		}
	}
}
