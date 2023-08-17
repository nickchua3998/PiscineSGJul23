/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:09:44 by hchua             #+#    #+#             */
/*   Updated: 2023/08/12 14:10:15 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	solve_largestsq(char *map_name)
{
	char	**map_tab;
	char	eof[3];
	int		mdepth;
	int		mwidth;
	int		j;

	map_tab = extract_map_tab(map_name, &mdepth, &mwidth, eof);
	if (map_tab != 0)
	{
		ft_fill_map(map_tab, mdepth, mwidth, eof);
		j = 0;
		while (j < mdepth)
		{
			ft_putstr(map_tab[j]);
			ft_putchar('\n');
			free(map_tab[j]);
			j++;
		}
		free(map_tab);
	}
	else
		ft_putstr("map error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	char		**map_name;
	char		inputstr[128];
	int			i;

	inputstr[0] = '\0';
	if (argc < 2)
	{
		ft_putstr("Please provide the name of the map file/s : ");
		fgets(inputstr, 128, 0);
		if (inputstr != '\0')
			map_name = ft_split(inputstr, " ");
		i = -1;
		while (map_name[i++])
			solve_largestsq(map_name[i]);
	}
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			solve_largestsq(argv[i]);
			i++;
		}
	}
	return (1);
}
