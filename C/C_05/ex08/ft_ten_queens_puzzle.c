/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:44:38 by hchua             #+#    #+#             */
/*   Updated: 2023/08/02 09:50:11 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	test_pos_safe(int table[10], int c_col, int c_row)
{
	int	col_ctr;

	col_ctr = -1;
	while (++col_ctr < c_col)
		if (c_row == table[col_ctr]
			|| col_ctr + table[col_ctr] == c_col + c_row
			|| col_ctr - table[col_ctr] == c_col - c_row)
			return (0);
	return (1);
}

void	ft_ten_queens_puzzle_recur(int table[10], int *res, int pos_ctr)
{
	int	row_ctr;
	int	print_ctr;

	if (pos_ctr == 10)
	{
		*res += 1;
		print_ctr = -1;
		while (++print_ctr < 10)
			ft_putchar(table[print_ctr] + '0');
		ft_putchar('\n');
	}
	else
	{
		row_ctr = -1;
		while (++row_ctr < 10)
		{	
			if (test_pos_safe(table, pos_ctr, row_ctr))
			{
				table[pos_ctr] = row_ctr;
				ft_ten_queens_puzzle_recur(table, res, pos_ctr + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
//int	main(void)
{
	int		table[10];
	int		i;
	int		res;

	i = -1;
	while (++i < 10)
		table[i] = -1;
	res = 0;
	ft_ten_queens_puzzle_recur(table, &res, 0);
	return (res);
}
