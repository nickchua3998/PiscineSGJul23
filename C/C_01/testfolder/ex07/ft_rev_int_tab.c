/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:00:20 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 10:14:25 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap((tab + i), (tab + size - 1 - i));
		i++;
	}
}
/*
#include <stdio.h>

void	putarr(int arr[], int size)
{
	int	i;

	i = -1;
	while (++i < size -1)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[size - 1]);
}	

int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	size;

	size = 9;
	printf("Original: ");
	putarr(tab, size);
	ft_rev_int_tab(tab, size);
	printf("Modified: ");
	putarr(tab, size);
}
*/
