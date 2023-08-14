/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:45:48 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 11:45:52 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	result = (malloc(sizeof(int) * length));
	if (result == NULL)
		return (0);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	ft_mul(int a)
{
	return (a * 3);
}

int	main(void)
{
	int i = 0;
	int tab[5] = {1, 2, 3, 4, 5};

	while (i<5)
	{
		printf("%d\n", ft_map(tab, 5, &ft_mul)[i]);
		i++;
	}
	return (0);
}
*/
