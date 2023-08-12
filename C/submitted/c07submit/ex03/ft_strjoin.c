/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:33:11 by hchua             #+#    #+#             */
/*   Updated: 2023/08/03 21:33:46 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	unsigned int	d;
	unsigned int	s;

	d = 0;
	s = 0;
	while (dest[d] != '\0')
		d++;
	while (src[s] != '\0')
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}

int	count_total_len(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{	
		len += size_sep + ft_strlen(strs[i]);
		i++;
	}
	len = len - size_sep;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	len = count_total_len(size, strs, ft_strlen(sep));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i + 1 < size)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}
/*
int	main(int argc, char **argv)
{
	char	*sep;

	sep = "1234";
	printf("The concatenated string: %s\n", ft_strjoin(argc, argv, sep));
}
*/
