/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:55:46 by hchua             #+#    #+#             */
/*   Updated: 2023/08/04 10:55:52 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

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
	while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v' )
	{
		*i += 1;
	}
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

int	parse_for_string(int argc, char **argv, char *str)
{
	int	i;

	i = 0;
	if (argc == 4)
	{
		while (argv[1][i] != '\0')
		{
			str[i] = argv[1][i];
			i++;
		}
		str[i] = '\0';
		i = 0;
	}
	return (0);
}

int	parse_for_base(int argc, char **argv, char *bf, char *bt)
{
	int	i;

	i = 0;
	if (argc == 4)
	{
		while (argv[2][i] != '\0')
		{
			bf[i] = argv[2][i];
			i++;
		}
		bf[i] = '\0';
		i = 0;
		while (argv[3][i] != '\0')
		{
			bt[i] = argv[3][i];
			i++;
		}
		bt[i] = '\0';
		return (1);
	}
	return (0);
}

char	*ft_str_appendchar(char *dest, char c)
{
	unsigned int	d;

	d = 0;
	while (dest[d] != '\0')
		d++;
	dest[d] = c;
	d++;
	dest[d] = '\0';
	return (dest);
}
