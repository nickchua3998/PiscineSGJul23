/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:27:22 by jiheng            #+#    #+#             */
/*   Updated: 2023/08/02 15:27:23 by jiheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_tab(char *tab[], int size)
{
	int		runs;
	char	*temp;
	int		repeat;

	runs = 1;
	while (runs < size)
	{
		repeat = 0;
		while (repeat < (size - runs))
		{
			if (ft_strcmp(tab[repeat], tab[repeat + 1]) > 0)
			{
				temp = tab[repeat];
				tab[repeat] = tab[repeat + 1];
				tab[repeat + 1] = temp;
			}
			repeat++;
		}
		runs++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	ft_sort_tab(&argv[1], argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
