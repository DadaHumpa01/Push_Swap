/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:31:15 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/20 13:23:57 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_a
{
	int			val;
	struct s_a	*next;
}				t_a;

typedef struct s_b
{
	int			val;
	struct s_b	*next;
}				t_b;

typedef struct s_world
{
	t_a			**a;
	t_b			**b;
	int			mosse;
}				t_world;

void	printlist(t_a **ciao, t_b **oi);
void	addnodedavanti(t_world *all, int val);
void	addnode(t_a **ciao, int val);
int		delete(t_a **ciao);
void	addnodeb_davanti(t_b **oi, int valore);
void	addnodeb_ultimo(t_b **oi, int valore);
int		delete_ultimonodeb(t_b **oi);
int		delete_nodeb(t_b **oi);
void	push_b(t_a **ciao, t_b **oi);
void	push_a(t_a **ciao, t_b **oi);
void	print_lista_a(t_a **ciao);
void	print_lista_b(t_b **oi);
void	free_word(t_world *all);

#	endif