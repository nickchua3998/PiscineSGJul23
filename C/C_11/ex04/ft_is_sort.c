/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:11:33 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 12:11:37 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sort_ascending(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_descending(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_ascending(tab, length, &(*f)) == 0
		&& ft_is_sort_descending(tab, length, &(*f)) == 0)
		return (0);
	return (1);
}
/*
#include <stdio.h>

int	ft_bminusa(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int i = 0;
	int tab[5] = {5, 5, 4, 3, 1};

	printf("%d\n", ft_is_sort(tab, 5, &ft_bminusa));
}
*/
