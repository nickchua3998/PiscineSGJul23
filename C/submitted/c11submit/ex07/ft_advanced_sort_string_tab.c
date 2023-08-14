/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:47:27 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 16:48:01 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_tab(char **tab, int size, int (*cmp)(char *, char *))
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < (size - i))
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	nooftab;

	nooftab = 0;
	while (tab[nooftab])
		nooftab++;
	ft_sort_tab(tab, nooftab, cmp);
}
/*
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int	i;

	ft_advanced_sort_string_tab(argv, &ft_strcmp);
	i = -1;
	while (++i < argc)
		printf("%s\n", argv[i]);
}
*/
