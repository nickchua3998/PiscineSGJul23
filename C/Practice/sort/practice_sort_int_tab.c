/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_sort_int_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:40:40 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 14:40:45 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if ((tab[j] - tab [j + 1]) < 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void	put_arr(int arr[], int size)
{
	int	i;

	i = -1;
	while (++i < size -1)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[size - 1]);
}	

int	main(void)
{
	int	tab[] = {2, 900, 3, 8, 50, 20, 7, 6, 4};
	int	size;

	size = 9;
	printf("Original: ");
	put_arr(tab, size);
	ft_sort_int_tab(tab, size);
	printf("Modified: ");
	put_arr(tab, size);
}

