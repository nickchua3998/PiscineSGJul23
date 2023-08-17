/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:09:44 by hchua             #+#    #+#             */
/*   Updated: 2023/08/12 14:10:15 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_index_num(int dict)
{
	char	c[1];
	char	*str;
	int		i;

	str = malloc(sizeof(char) * 128);
	if (str == NULL)
		return (0);
	i = 0;
	read(dict, c, 1);
	while (c[0] == '\n')
		read(dict, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(dict, c, 1);
		i++;
	}
	return (str);
}

char	*get_writestr(int dict, char *c)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * 128);
	if (str == NULL)
		return (0);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(dict, c, 1);
		i++;
	}
	return (str);
}

t_list	*extract_tab(char *file)
{
	char	c[1];
	t_list	*tab;
	int		i;
	int		dict;

	dict = open(file, O_RDONLY);
	if (dict == -1)
		ft_putstr("Cannot read file.\n");
	tab = malloc(sizeof(t_list) * 35);
	if (tab == NULL || dict == -1)
		return (0);
	i = -1;
	while (++i < 35)
	{
		tab[i].nb = ft_atoi(get_index_num(dict));
		read(dict, c, 1);
		while (c[0] == ' ' || c[0] == ':')
			read(dict, c, 1);
		tab[i].val = ft_strdup(get_writestr(dict, c));
	}
	close(dict);
	return (tab);
}
