/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:13:28 by hchua             #+#    #+#             */
/*   Updated: 2023/08/16 16:13:33 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_gen_map(int depth, int width)
{
	char	**map_soln;
	int		row;

	map_soln = (char **)malloc(depth * sizeof(char *));
	if (map_soln == NULL)
		return (NULL);
	row = 0;
	while (row < depth)
	{
		map_soln[row] = (char *)malloc(width * sizeof(char));
		if (map_soln[row] == NULL)
			return (NULL);
		row++;
	}
	return (map_soln);
}

int	is_eof(char c, char *charset)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
