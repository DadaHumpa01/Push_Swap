/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:51:18 by danilo            #+#    #+#             */
/*   Updated: 2021/05/16 12:29:55 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		delete_ultimo(t_a **ciao)
{
	t_a *tmp;
	int valore;

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
	t_a *tmp;

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
	t_a *tmp;

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