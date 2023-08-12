/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:55:22 by hchua             #+#    #+#             */
/*   Updated: 2023/08/04 10:55:31 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_str_appendchar(char *dest, char c);
int		ft_find_base_pos(char str, char *base);
int		extract_sign(char *str, int *i);
int		parse_for_string(int argc, char **argv, char *str);
int		parse_for_base(int argc, char **argv, char *bf, char *bt);

char	*output_basechr_recur(int nbr, char *base, int baselen, char *result)
{
	unsigned int		n;
	char				print;

	if (nbr < 0)
	{
		n = nbr * (-1);
		ft_str_appendchar(result, '-');
	}
	else
		n = nbr;
	if (n >= (unsigned int)baselen)
		output_basechr_recur(n / baselen, base, baselen, result);
	print = base[n % baselen];
	ft_str_appendchar(result, print);
	return (result);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	bflen;
	int	nbr;
	int	sign;
	int	i;
	int	tmp;

	i = 0;
	nbr = 0;
	bflen = baselen_if_acceptable(base);
	if (bflen != 0)
	{
		sign = extract_sign(str, &i);
		tmp = ft_find_base_pos(str[i], base);
		while (tmp != -1)
		{
			nbr = (nbr * bflen) + tmp;
			i++;
			tmp = ft_find_base_pos(str[i], base);
		}
		return (nbr * sign);
	}
	return (0);
}

char	*ft_putnbr_base(int nbr, char *base, char *result)
{
	int	btlen;

	btlen = baselen_if_acceptable(base);
	if (btlen != 0)
		output_basechr_recur(nbr, base, btlen, result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_10int;
	char	*result;

	if (baselen_if_acceptable(base_from) == 0
		|| baselen_if_acceptable(base_to) == 0)
		return (0);
	result = (char *)malloc(sizeof(char) * 34);
	if (result == NULL)
		return (NULL);
	nbr_10int = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(nbr_10int, base_to, result);
	return (result);
}
