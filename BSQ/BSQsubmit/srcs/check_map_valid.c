/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:05:45 by hchua             #+#    #+#             */
/*   Updated: 2023/08/16 23:06:16 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**extract_map_tab(char *mapfile, int *mdepth, int *mwidth, char *eof)
{
	char	c[1];
	char	**map_tab;
	int		mapfd;
	int		i;
	int		j;

	if (map_eof_is_valid(mapfile, mdepth, mwidth, eof) == 1)
	{
		mapfd = open(mapfile, O_RDONLY);
		if (mapfd == -1)
		{
			ft_putstr("Cannot read file\n");
			return (0);
		}
		map_tab = ft_gen_map(*mdepth, *mwidth);
		read(mapfd, c, 1);
		while (c[0] != '\n')
			read(mapfd, c, 1);
		read(mapfd, c, 1);
		i = 0;
		while (i < *mdepth)
		{
			j = 0;
			while (j < *mwidth && is_eof(c[0], eof))
			{
				map_tab[i][j] = c[0];
				read(mapfd, c, 1);
				j++;
			}
			read(mapfd, c, 1);
			i++;
		}
		close(mapfd);
		return (map_tab);
	}
	return (0);
}

int	map_eof_is_valid(char *mapfile, int *mdepth, int *mwidth, char *eof)
{
	char	c[1];
	int		i;
	int		m_row;
	int		mapfd;

	*mdepth = 0;
	mapfd = open(mapfile, O_RDONLY);
	if (mapfd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	read(mapfd, c, 1);
	if (c[0] == '\0')
		return (0);
	while ((c[0] != '\n') && (c[0] >= '0' && c[0] <= '9'))
	{
		*mdepth = (*mdepth * 10) + (c[0] - 48);
		read(mapfd, c, 1);
	}
	if (c[0] == '\n')
	{
		eof[0] = (*mdepth % 1000) / 100 + 48;
		eof[1] = (*mdepth % 100) / 10 + 48;
		eof[2] = (*mdepth % 10) + 48;
		*mdepth = *mdepth / 1000;
	}
	else
	{	
		i = -1;
		while (c[0] != '\n')
		{
			eof[++i] = c[0];
			read(mapfd, c, 1);
		}
		if (i != 2)
			return (0);
	}
	if (eof[0] == eof [1] || eof[1] == eof[2] || eof[0] == eof[2])
		return (0);
	read(mapfd, c, 1);
	m_row = 0;
	i = 1;
	if (c[0] == '\n' || c[0] == '\0')
		return (0);
	while (read(mapfd, c, 1) != '\0')
	{
		if (c[0] == '\n')
		{
			if (m_row == 0)
				*mwidth = i;
			if (*mwidth != i)
				return (0);
			m_row++;
			i = -1;
		}
		i++;
	}
	if (*mdepth != m_row)
		return (0);
	return (1);
}
