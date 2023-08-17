/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:58:21 by hchua             #+#    #+#             */
/*   Updated: 2023/08/14 21:58:29 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	**ft_generate_map(int l, int c)
{
	int	**map2;
	int	i;

	i = 0;
	map2 = malloc(l * sizeof(int *));
	if (map2 == NULL)
		return (NULL);
	while (i < l)
	{
		map2[i] = malloc(c * sizeof(int));
		if (map2[i] == NULL)
			return (NULL);
		i++;
	}
	return (map2);
}

int	ft_biggest_square(char **map, int c, int l, char o)
{
	int	i;
	int	j;
	int	**c_m;
	int	count_max;

	i = 0;
	count_max = 0;
	c_m = ft_generate_map(l, c);
	while (i < l)
	{
		j = 0;
		while (j < c - 1)
		{
			if (map[i][j] == o)
				c_m[i][j] = 0;
			else if (i == 0 || j == 0)
				c_m[i][j] = 1;
			else
				c_m[i][j] = ft_min(c_m[i - 1][j], c_m[i][j - 1], c_m[i - 1][j - 1]) + 1;
			if (c_m[i][j] > count_max)
				count_max = c_m[i][j];
			j++;
		}
		i++;
	}
	free(c_m);
	return (count_max);
}

int	ft_find_posn_sq(char **map, int *mwidth, int *mdepth, char *obst)
{
	int	i;
	int	j;
	int	**c_m;
	int	count_max;
	int	p;

	c_m = NULL;
	i = 0;
	p = 0;
	count_max = ft_biggest_square(map, *mwidth, *mdepth, *obst);
	c_m = ft_generate_map(*mdepth, *mwidth);
	while (i < *mdepth)
	{
		j = 0;
		while (j < *mwidth - 1)
		{
			if (map[i][j] == *obst)
				c_m[i][j] = 0;
			else if (i == 0 || j == 0)
				c_m[i][j] = 1;
			else
				c_m[i][j] = ft_min(c_m[i - 1][j], c_m[i][j - 1], c_m[i - 1][j - 1]) + 1;
			if (c_m[i][j] == count_max)
			{
				p = i * (*mwidth - 1) + j;
				break ;
			}
			j++;
		}
		i++;
	}
	free (c_m);
	return (p);
}
