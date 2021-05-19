#include "pushswap.h"

int main(int ac, char **av)
{
	t_a **a;
	t_b **b;

	a = (t_a **)malloc(sizeof(t_a *));
	b = (t_b **)malloc(sizeof(t_b *));
	*a = NULL;
	*b = NULL;
	addnode(a, 1);
	addnode(a, 2);
	addnode(a, 3);
	addnode(a, 4);
	printlist(a, b);
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	printlist(a, b);
	push_a(a, b);
	printlist(a, b);
}