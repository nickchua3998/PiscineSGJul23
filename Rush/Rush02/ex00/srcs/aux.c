/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:47:27 by hchua             #+#    #+#             */
/*   Updated: 2023/08/12 14:47:35 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned long long int	ft_atoi(const char *str)
{
	unsigned long long int		res;
	unsigned long long int		res_before;

	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res_before = res;
		res = res * 10 + (*str - 48);
		if (res_before > res)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		++str;
	}
	return (res);
}

int	ft_atoi_sign(const char *str)
{
	int					negative;

	negative = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	if (negative == -1)
		return (-1);
	return (0);
}

unsigned long long int	get_10mult(unsigned long long int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

unsigned long long int	get_mult(unsigned long long int nb)
{
	if (nb >= 1000000000000000000)
		return (1000000000000000000);
	else if (nb >= 1000000000000000)
		return (1000000000000000);
	else if (nb >= 1000000000000)
		return (1000000000000);
	else if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (get_10mult(nb));
}
