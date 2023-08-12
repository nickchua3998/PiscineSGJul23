/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:46:41 by hchua             #+#    #+#             */
/*   Updated: 2023/07/31 11:46:44 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_basechr_recur(int nbr, char *base, int base_size)
{
	unsigned int	n;
	char			print;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)base_size)
		output_basechr_recur(n / base_size, base, base_size);
	print = base[n % base_size];
	write(1, &print, 1);
}

int	if_base_acceptable(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	basesize;

	basesize = 0;
	if (if_base_acceptable(base) == 1)
	{
		while (base[basesize] != '\0')
			basesize++;
		output_basechr_recur(nbr, base, basesize);
	}
}
/*
int	main(void)
{
	ft_putnbr_base(2147483648, "01");
}
*/
