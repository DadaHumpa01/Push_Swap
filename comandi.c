/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danilo <danilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:49:10 by danilo            #+#    #+#             */
/*   Updated: 2021/05/16 18:36:06 by danilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    push_a(t_a **ciao, t_b **oi)
{
    if (*ciao == NULL)
        return ;
    addnodedavanti(ciao, (*oi)->val);
    delete_nodeb(oi);
}

void    push_b(t_a **ciao, t_b **oi)
{
    if (*ciao == NULL)
        return ;
    addnodeb_davanti(oi, (*ciao)->val);
    delete(ciao);
}   

