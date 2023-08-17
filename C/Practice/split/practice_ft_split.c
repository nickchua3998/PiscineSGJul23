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
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	is_sep(char c, char *charset)
{
	int	i;
	
	i = 0;
	while (charset[i] != '\0')
	{
		if ( c == charset[i])
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
		if (is_sep(str[i + 1], charset) == 1
			&& is_sep(str[i], charset) == 0)
			c_addr++;
		i++;
	}
	return (c_addr);
}

void	addr_dup(char *dest, char *str, char *charset)
{
	int	i;
	
	i = 0;
	while (is_sep(str[i], charset) == 0)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

void	insert_addr(char **tab, char *str, char *charset)
{
	int	i;
	int	j;
	int	c_addr;
	
	c_addr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while(is_sep(str[i + j], charset) == 0)
				j++;
			tab[c_addr] = (char *)malloc(sizeof(char) * (j + 1));
			addr_dup(tab[c_addr], str + i, charset);
			i += j;
			c_addr++;	
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	c_addr;
	char	**tab;
	
	c_addr = count_addr(argv[1], argv[2]);
	tab = (char **)malloc(sizeof(char *) * (c_addr + 1));
	tab[c_addr] = NULL;
	insert_addr(tab, argv[1], argv[2]);
	i = 0;
	while(tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		free(tab[i]);
		i++;	
	}
	free(tab);
}
