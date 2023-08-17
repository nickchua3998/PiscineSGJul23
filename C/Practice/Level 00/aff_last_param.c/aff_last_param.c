/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:30:08 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 16:30:11 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		ft_putchar('\n');
	else
	{
		i = 0;
		while (argv[argc -1][i] != '\0')
		{
			ft_putchar(argv[argc -1][i]);
			i++;
		}
		ft_putchar('\n');
	}
}
