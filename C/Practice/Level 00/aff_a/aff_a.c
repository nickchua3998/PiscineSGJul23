/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:27:45 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 15:27:49 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		ft_putchar('a');
	else
	{	
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'a')
			{	
				ft_putchar('a');
				break ;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
