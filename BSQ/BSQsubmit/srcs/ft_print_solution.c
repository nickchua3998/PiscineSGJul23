/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:57:03 by hchua             #+#    #+#             */
/*   Updated: 2023/08/14 21:57:07 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_fill_map(char **map, int c, int l, char *eof)
{
	int	i;
	int	j;
	int	length;
	int	pos;

	length = ft_biggest_square(map, c, l, eof[1]);
	pos = ft_find_posn_sq(map, &c, &l, &eof[1]);
	i = (pos / (c - 1)) - length + 1;
	while (i < (pos / (c - 1)) + 1)
	{
		j = (pos % (c -1)) - length + 1;
		while (j < (pos % (c -1)) + 1)
		{
			map[i][j] = eof[2];
			j++;
		}
		i++;
	}
	return (map);
}
