#include "pushswap.h"

void	list_init(t_world *all)
{
	all->a = (t_a **)malloc(sizeof(t_a *));				//inilizzazione lista a
	if (all->a == NULL)
		exit(1);
	*all->a = NULL;
	all->b = (t_b **)malloc(sizeof(t_b *));				//inilizzazione lista b
	if (all->b == NULL)
		free_word(all);
	*all->b = NULL;
	all->mosse = 0;
}

int main(int ac, char **av)
{
	t_world all;

	list_init(&all);
	addnodedavanti(&all, 113);
	addnodedavanti(&all, 119);
	addnodeb_davanti(&all, 118);
	addnodeb_davanti(&all, 119);
	addnodeb_davanti(&all, 120);
	addnode(&all, 10);
	printlist(&all);
	reverse_rotate_a_b(&all);
	printlist(&all);
}