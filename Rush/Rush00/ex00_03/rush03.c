/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhilim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:44:44 by zhilim            #+#    #+#             */
/*   Updated: 2023/07/29 16:22:18 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char icon);

void	print_row(int t_c, char start, char mid, char end)
{
	int	c;

	c = 1;
	while (c <= t_c)
	{
		if (c == 1 && t_c >= 2)
			ft_putchar(start);
		else if (c == 1 && t_c < 2)
		{
			ft_putchar(start);
			ft_putchar('\n');
		}
		else if (c > 1 && c < t_c)
			ft_putchar(mid);
		else
		{
			ft_putchar(end);
			ft_putchar('\n');
		}
		c++;
	}
}

void	rush(int t_c, int t_r)
{
	int	r;

	r = 1;
	while (r <= t_r)
	{
		if (r == 1)
			print_row(t_c, 'A', 'B', 'C');
		else if (r > 1 && r < t_r)
			print_row(t_c, 'B', ' ', 'B');
		else
			print_row(t_c, 'A', 'B', 'C');
		r++;
	}
}
