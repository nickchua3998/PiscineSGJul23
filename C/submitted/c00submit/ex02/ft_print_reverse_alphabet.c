/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:39:46 by hchua             #+#    #+#             */
/*   Updated: 2023/07/26 17:43:48 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	int	i;

	i = 26;
	while (i > 0)
	{
		i--;
		ft_putchar(i + 97);
	}
}

/*
void	main(void)
{
	ft_print_reverse_alphabet();
}
*/
