/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:47:08 by hchua             #+#    #+#             */
/*   Updated: 2023/07/31 11:47:14 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	baselen_if_acceptable(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-'
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_find_base_pos(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	extract_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] > 8 && str[*i] < 14) || str[*i] == 32)
		*i += 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	blen;
	int	nbr;
	int	sign;
	int	i;
	int	bnbr_toi;

	i = 0;
	nbr = 0;
	blen = baselen_if_acceptable(base);
	if (blen != 0)
	{
		sign = extract_sign(str, &i);
		bnbr_toi = ft_find_base_pos(str[i], base);
		while (bnbr_toi != -1)
		{
			nbr = (nbr * blen) + bnbr_toi;
			i++;
			bnbr_toi = ft_find_base_pos(str[i], base);
		}
		return (nbr * sign);
	}
	return (0);
}
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	parse_for_string(int argc, char **argv, char *inputstr, char *bradix)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			inputstr[i] = argv[1][i];
			i++;
		}
		inputstr[i] = '\0';
		i = 0;
		while (argv[2][i] != '\0')
		{
			bradix[i] = argv[2][i];
			i++;
		}
		bradix[i] = '\0';
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	inputstr[100];
	char	base[100];
	int	nbr;

	parse_for_string(argc, argv, inputstr, base);
	printf("input str = %s, base str = %s\n", inputstr, base);
	nbr = ft_atoi_base(inputstr, base);
	ft_putnbr(nbr);
}
*/
