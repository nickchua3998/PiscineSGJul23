/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhilim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:44:44 by zhilim            #+#    #+#             */
/*   Updated: 2023/07/30 17:53:20 by zhilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	parse_argument(int argc, char **argv, int *column, int *row)
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
			{
				if (j == 1)
					*column = *column * 10 + (argv[j][i] - '0');
				else if (j == 2)
					*row = *row * 10 + (argv[j][i] - '0');
			}
			else
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}



int	main(int argc, char **argv)
{
	int	column;
	int	row;

	column = 0;
	row = 0;
	parse_argument(argc, argv, &column, &row);
	rush(column, row);
	return (0);
}
