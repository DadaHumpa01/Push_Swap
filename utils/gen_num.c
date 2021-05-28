/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:12:16 by dbrignon          #+#    #+#             */
/*   Updated: 2021/05/28 14:12:18 by dbrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1000

int main (int ac, char **av)
{
 	int		i, n, num, x;
   	time_t	t;
	int		*numbers;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n > MAX)
		return (printf("Error, limit is %d\n", MAX));
	numbers = (int *)malloc(sizeof(int) * n);
	srand((unsigned) time(&t));
	i = -1;
	while (++i < n)
	{
		num = rand() % MAX;
		numbers[i] = num;
		x = -1;
		while (++x < i)
			if (num == numbers[x])
				x = i--;
	}
	i = -1;
	while (++i < n)
		printf("%d ", numbers[i]);
	free(numbers);
	return (0);
}