/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:37:49 by hchua             #+#    #+#             */
/*   Updated: 2023/08/03 16:37:54 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (0);
	i = -1;
	while (++i < max - min)
		tab[i] = min + i;
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*tab;
	int	min;
	int	max;

	min = -5;
	max = 5;
	tab = ft_range(min, max);
	if (tab != NULL)
	{
		i = -1;
		while (++i < max - min)
		{
			printf("%d, ", tab[i]);
		}
	}
}
*/
