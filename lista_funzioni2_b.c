/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lista_funzioni2_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:53:22 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/19 09:58:25 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_lista_b(t_b **oi)
{
	t_b	*tmp;

	if (*oi == NULL)
		printf("lista b vuota\n");
	else
	{
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
