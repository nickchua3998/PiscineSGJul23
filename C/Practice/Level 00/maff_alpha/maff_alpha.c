/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:58:31 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 15:58:34 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	main(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
			ft_putchar('a' + i);
		else
			ft_putchar('a' + i - 32);
		i++;
	}
	ft_putchar('\n');
}