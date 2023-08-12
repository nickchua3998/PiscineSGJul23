/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:55:18 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/09 16:54:06 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i_src;
	unsigned int	i_dest;

	i_src = 0;
	i_dest = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (src[i_src] != '\0')
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[i_dest + i_src] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
/*
Write a function that will concatenate all the strings
	pointed by strs separated by sep.

size is the number of strings in strs

if size is 0, you must return an empty string that you can free().

Here’s how it should be prototyped :
	char *ft_strjoin(int size, char **strs, char *sep);
*/
{
	int		i;
	int		chars;
	char	*str;

	i = -1;
	chars = 1;
	while (++i < size)
	{
		chars += ft_strlen(strs[i]);
		if (i < size - 1)
			chars += ft_strlen(sep);
	}
	str = (char *)malloc((chars) * sizeof(char));
	if (!str)
		return (0);
	str[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
	}
	return (str);
}

/*TEST
#include <stdio.h>

int	main(void)
{

	char	*strs[] = {
		"hello",
		"world",
		"!"
	};
	char *joined = ft_strjoin(3, strs, ", ");
	printf("%s\n", joined);
	int i = 0;
	printf("%s\n", joined);
	while (joined[i])
	{
		printf("%c |", joined[i]);
		i++;
	}
	free(joined);
}
TEST*/
