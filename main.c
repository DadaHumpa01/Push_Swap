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
	addnode(&all, 10);
	printlist(&all);
	swap_a(&all);
	printlist(&all);
}