/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:31:15 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/27 17:01:56 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_a
{
	int			val;
	int			index;
	int			dim_list;
	struct s_a	*next;
}				t_a;

typedef struct s_b
{
	int			val;
	int			pos;
	int			pos_in_stack;
	int			mosse;
	struct s_b	*next;
}				t_b;

typedef struct s_world
{
	t_a			**a;
	t_b			**b;
	int			mosse;
	int			val_close_list;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
}				t_world;

void	printlist(t_world *all);
void	addnodedavanti(t_world *all, int val);
void	addnode(t_world *all, int val);
int		delete(t_world *all);
void	addnodeb_davanti(t_world *all, int valore);
void	addnodeb_ultimo(t_world *all, int valore);
int		delete_ultimonodeb(t_world *all);
int		delete_nodeb(t_world *all);
void	print_lista_a(t_world *all);
void	print_lista_b(t_world *all);
void	free_word(t_world *all);
int		delete_ultimo(t_world *all);
int		ricerca_valore(t_world *all, int domanda);
void	swap_a(t_world *all);
void	swap_b(t_world *all);
void	swap_a_b(t_world *all);
void	push_b(t_world *all);
void	push_a(t_world *all);
void	rotate_a(t_world *all);
void	rotate_b(t_world *all);
void	rotate_a_b(t_world *all);
void	reverse_rotate_a(t_world *all);
void	reverse_rotate_b(t_world *all);
void	reverse_rotate_a_b(t_world *all);
void	parsing(int ac, char **av, t_world *all);
int		Iatoi(char *str);
void	error(void);
void	list_init(t_world *all);
void	delete_list_a(t_world *all);
void	delete_list_b(t_world *all);
int		dim_list_a(t_world *all);

/* 	Operazioni per definirie un Index nella lista */

void	set_index(t_world *all);
void	check_value_index(t_world *all);
void	recursive_index(t_world *all, int indice);
void	split_list_a(t_world *all);
int		check_list_a_ultimo(t_world *all);
void	check_value(t_world *all);
void	move_in_b_by_index(t_world *all, t_a *tmp);
void	new_list_recursive(t_world *all);
void	check_pos(t_world *all);
int		dim_list_a_recursive(t_a *tmp, int cont);

/* operazione per l'ordinamento in b */

void	check_pos_num_b(t_world *all, t_b *aux, int pos);
void	calculate_mosse(t_world *all, t_b *aux);
int		dim_list_b_recursive(t_b *aux, int cont);
int		trova_pos_recursive(t_a *tmp, int num, int pos);
int		trova_numero_meno_mosse(t_b *aux, int num, int mosse);
void	assign_pos_list(t_world *all, t_b *tmp);
void	calculate_best_option(t_world *all, int num);
void	init_moss(t_world *all);
void	make_me_move(t_world *all);

#	endif