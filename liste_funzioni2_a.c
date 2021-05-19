/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_funzioni2_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:51:18 by danilo            #+#    #+#             */
/*   Updated: 2021/05/19 09:52:03 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	delete_ultimo(t_a **ciao)
{
	t_a		*tmp;
	int		valore;

	if (*ciao == NULL)
		return (-1);
	tmp = *ciao;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	return (valore);
}

void	delete_list(t_a **ciao)
{
	t_a	*tmp;

	if (*ciao == NULL)
		return ;
	while (*ciao != NULL)
	{
		tmp = (*ciao)->next;
		free(*ciao);
		*ciao = tmp;
	}
}

t_a	*ricerca_valore(t_a **ciao, int domanda)
{
	t_a	*tmp;

	if (*ciao == NULL)
		return (NULL);
	tmp = *ciao;
	while (tmp->next != NULL)
	{
		if (tmp->val == domanda)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (NULL);
}

void	print_lista_a(t_a **ciao)
{
	t_a	*tmp;

	if (*ciao == NULL)
		printf("lista a vouta\n");
	else
	{
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
}