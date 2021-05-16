#ifndef 	TEST_H
# define	TEST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_a
{
	int val;
	struct s_a *next;
}				t_a;

typedef struct	s_b
{
	int val;
	struct s_b *next;
}				t_b;

void	printlist(t_a **ciao, t_b **oi);
void	addnodedavanti(t_a **ciao, int val);
void	addnode(t_a **ciao, int val);
int		delete(t_a **ciao);
void	addnodeb_davanti(t_b **oi, int valore);
void	addnodeb_ultimo(t_b **oi, int valore);
int		delete_ultimonodeb(t_b **oi);
int		delete_nodeb(t_b **oi);
void    push_b(t_a **ciao, t_b **oi);
void    push_a(t_a **ciao, t_b **oi);

#endif