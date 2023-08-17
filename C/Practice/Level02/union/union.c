/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:34:55 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 17:34:57 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_not_repeat(char *str, char c, int max_pos)
{
	int	i;

	i = 0;
	while (i < max_pos)
	{
		if (str[i] == c)
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (is_not_repeat(argv[1], argv[1][i], i) == 1)
			ft_putchar(argv[1][i]);
		i++;
	}
	j = 0;
	while (argv[2][j] != '\0')
	{
		if ((is_not_repeat(argv[1], argv[2][j], i) == 1)
			&& (is_not_repeat(argv[2], argv[2][j], j) == 1))
			ft_putchar(argv[2][j]);
		j++;
	}
	ft_putchar('\n');
	return (1);
}
