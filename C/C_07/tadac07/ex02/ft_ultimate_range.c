/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:23:06 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/07 18:38:06 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
/*
Create a function ft_ultimate_range which allocates
	and assigns an array of ints.

This int array should contain all values between min and max.

Min included - max excluded.

Here’s how it should be prototyped :
	int ft_ultimate_range(int **range, int min, int max);

The size of range should be returned (or -1 on error).

If the value of min is greater or equal to max’s value, range will point on NULL
and it should return 0.
*/
{
	int	i;
	int	range_len;
	int	*range_array;

	*range = 0;
	if (min >= max)
		return (0);
	range_len = max - min;
	range_array = (int *)malloc(range_len * sizeof(int));
	if (range_array == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		range_array[i] = min;
		i++;
		min++;
	}
	*range = range_array;
	return (range_len);
}

/*TEST
#include <stdio.h>
#include <string.h>

void	test(int	input_1, int input_2)
{
	int 	i;
	int		*range = 0;
	int		actual = ft_ultimate_range(&range, input_1, input_2);

	printf("\n%d [", actual);
	i = 0;
	while (i < input_2 - input_1)
	{
		printf("%d, ", range[i]);
		i++;
	}
	printf("]");
	free(range);
}

int	main(void)
{
	test(-2, 5);
	test(0, 10);
	test(13, 90);
}
TEST*/
