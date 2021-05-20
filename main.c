#include "pushswap.h"
/*
void	list_init(t_world **all)
{
	all = (t_world *)malloc(sizeof(t_world));						//inilizzazione lista all
	if (all == NULL)
		exit(1);
	*all->a = (t_a **)malloc(sizeof(t_a *));				//inilizzazione lista a
	if (all->a == NULL)
		free_word(all);
	*all->a = NULL;
	all->b = (t_b **)malloc(sizeof(t_b *));				//inilizzazione lista b
	if (all->b == NULL)
		free_word(all);
	*all->b = NULL;
	all->mosse = 0;
	printf("Puntatore struttura contenitore %p\n", all);
	printf("Puntatore lista a: %p\n", all->a);
	printf("Puntatore lista a: %p\n", *all->a);
	printf("Puntatore lista b: %p\n", all->b);
	printf("Puntatore lista b: %p\n", *all->b);
	printf("Inilizzazione numero di mosse: %d\n", all->mosse);
}
*/

int	atoi_mod(char *str)
{
	int val;
	int i;

	i = 0;
	val = 0;
	while (str != '\0')
	{
		if (str[i] == 32 || str[i] == 45)
			i++;
		if (str[i] == 43)
		{	
			val = val * -1;
			i++;
		}
		if (str[i] <= 48 || str[i] >= 57)
		{
			val = str[i] - '0' * 10;
			i++;
		}
	}
	return (val);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	printf("%d\n", ac);
	if (ac > 1)
	{
		while (ac != i)
		{
			printf("argomento %d: %s\n",i, av[i]);
			i++;
		}
	}
	else
		printf("Error aggiungimi un argomento");
}