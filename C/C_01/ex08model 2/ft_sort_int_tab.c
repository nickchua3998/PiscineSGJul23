/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:59:21 by emanimol          #+#    #+#             */
/*   Updated: 2023/08/01 19:23:37 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	sorted;
	int	i;
	int	swap;

	sorted = 0;
	while (sorted != 1)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
				sorted = 0;
			}
			i++;
		}
	}
}

int	main(void)
{
	int	tab[13] = {3, 5, 2, 1, 10, 8, 7, 4, 200, 101000928, 96, 32, 535};
	int	size;
	int	i;

	i = 0;
	size = 13;
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%i\n", tab[i]);
		i++;
	}
	ft_sort_int_tab(tab, size);
	return (0);
}

