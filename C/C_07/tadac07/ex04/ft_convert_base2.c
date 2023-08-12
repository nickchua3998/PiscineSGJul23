/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:15:24 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/08 12:17:18 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-' || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	compute_result(char *str, char *base)
{
	int	result;
	int	base_idx;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	result = 0;
	base_idx = is_base(*str, base);
	while (*str && base_idx >= 0)
	{
		result = (result * base_len) + base_idx;
		str++;
		base_idx = is_base(*str, base);
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;

	if (!is_base_valid(base))
		return (0);
	while (is_space(*str))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (compute_result(str, base) * sign);
}
