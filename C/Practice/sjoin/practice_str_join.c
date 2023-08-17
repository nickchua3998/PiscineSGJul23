/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_str_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:48 by hchua             #+#    #+#             */
/*   Updated: 2023/08/16 10:31:58 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_total_len(int size, char **str, char *sep)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(str[i]) + ft_strlen(sep);
		i++;
	}
	return (len - ft_strlen(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		total_len;
	int	len_sep;

	if (size == 0)
	{
		dest = (char *)malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	total_len = count_total_len(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * (total_len + 1));
	if (dest == NULL)
		return (0);
	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	char	*sep;

	sep = "####";
	printf("The concatenated string: %s\n", ft_strjoin(argc, argv, sep));
}
