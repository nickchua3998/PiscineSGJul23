/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:08:38 by hchua             #+#    #+#             */
/*   Updated: 2023/08/06 14:08:43 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_char_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_addr(char *str, char *charset)
{
	int	i;
	int	c_addr;

	c_addr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_char_sep(str[i + 1], charset) == 1
			&& is_char_sep(str[i], charset) == 0)
			c_addr++;
		i++;
	}
	return (c_addr);
}

void	copy_addr(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_char_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	insert_addr(char **addrlist, char *str, char *charset)
{
	int		i;
	int		j;
	int		c_addr;

	c_addr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_char_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_char_sep(str[i + j], charset) == 0)
				j++;
			addrlist[c_addr] = (char *)malloc(sizeof(char) * (j + 1));
			copy_addr(addrlist[c_addr], str + i, charset);
			i += j;
			c_addr++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**addrlist;
	int		c_addr;

	c_addr = count_addr(str, charset);
	addrlist = (char **)malloc(sizeof(char *) * (c_addr + 1));
	addrlist[c_addr] = 0;
	insert_addr(addrlist, str, charset);
	return (addrlist);
}
