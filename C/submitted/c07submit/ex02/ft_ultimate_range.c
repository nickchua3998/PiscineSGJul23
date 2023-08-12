/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:05:09 by hchua             #+#    #+#             */
/*   Updated: 2023/08/03 18:05:19 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * (max - min));
	if (tab == NULL)
		return (-1);
	i = -1;
	while (++i < max - min)
		tab[i] = min + i;
	*range = tab;
	return (i);
}
/*
#include <stdio.h>

void	print_test(int *test, int size)
{
	int i;

	for (i = 0; i < size - 1; i++)
	{
		printf("%d - ", test[i]);
	}
	if (size > 0)
		printf("%d\n", test[size - 1]);
}

int	main(void)
{
	int min;
	int max;
	int size;
	int *test;

	min = 0;
	max = 11;
	size = ft_ultimate_range(&test, min, max);
	printf("size = %d\n", size);
	print_test(test, size);
	free(test);
}
*/
/*	TEST CASES:
	test(3, 5) -> size = 2	 >	3 - 4
	test(0, 11) -> size = 11 > 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10
	test(8, 2) -> size = 0
	test(2, 2) -> size = 0
	test(10, 20) -> size = 10 > 10 - 11 - 12 - 13 - 14 - 15 - 16 - 17 - 18 - 19

	test(20, 15) -> size = 0
	test(99, 99) -> size = 0
	test(1, 12) -> size = 11 > 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 - 11
*/
