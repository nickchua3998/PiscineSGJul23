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

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	*rev_tab;

	while size != 0
	{
		size--;
		rev_tab = *(tab + size);
		rev_tab++;
	}
	return(rev_tab);
}

void putarr(int arr[], int size)
{
    for (int i = 0; i < (size -1); i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[size - 1]);
}

int	main (void)
{
	int tab[] = {1, 2, 3, 4};
	int size;

	size = 4;

	printf("Original: ");
	putarr(tab, size);

	ft_rev_int_tab(tab, size);

	printf("Modified: ");
	putarr(tab, size);
}
