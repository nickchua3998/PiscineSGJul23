/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:36:32 by hchua             #+#    #+#             */
/*   Updated: 2023/07/29 11:59:10 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	go_next_row(void)
{
	ft_putchar ('\n');
}

void	print_first_last_row(int width)
{
	int	col;

	col = 1;
	ft_putchar('o');
	col++;
	while (col < width)
	{
		ft_putchar ('-');
		col++;
	}
	if (width > 1)
		ft_putchar ('o');
}

void	print_mid_row(int width)
{
	int	col;

	col = 1;
	while (col <= width)
	{
		if (col == 1 || col == width)
			ft_putchar ('|');
		else
			ft_putchar (' ');
		col++;
	}
}

int	rush(int width, int height)
{
	int	row;

	row = 1;
	print_first_last_row(width);
	go_next_row();
	row++;
	while (row < height)
	{
		print_mid_row(width);
		go_next_row();
		row++;
	}
	if (height > 1)
	{
		print_first_last_row(width);
		go_next_row();
	}
}
