/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:34:43 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/07 18:37:30 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
/*
Create a function ft_range which returns an array ofints. This int array should
	contain all values between min and max.

Min included - max excluded.

Here’s how it should be prototyped :
	int *ft_range(int min, int max);

If min ́value is greater or equal to max’s value,
	a null pointer should be returned.
*/
{
	int	i;
	int	range_len;
	int	*range_array;

	if (min >= max)
		return (0);
	i = 0;
	range_len = max - min;
	range_array = (int *)malloc(range_len * sizeof(int));
	range_array = (int *)malloc(range_len * sizeof(int));
	while (min < max)
	{
		range_array[i] = min;
		i++;
		min++;
	}
	return (range_array);
}

/*TEST
#include <stdio.h>
#include <string.h>

void	test(int	input_1, int input_2)
{
	int 	i;
	int*	actual = ft_range(input_1, input_2);

	printf("\n[");
	i = 0;
	while (i < input_2 - input_1)
	{
		printf("%d, ", actual[i]);
		i++;
	}
	printf("]");
	free(actual);
}

int	main(void)
{
	test(-2, 5);
	test(0, 10);
	test(13, 90);
}
TEST*/
