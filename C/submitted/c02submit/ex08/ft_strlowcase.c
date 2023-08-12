/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:51:43 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 15:52:20 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 65) && (str[c] <= 90))
			str[c] += 32;
		c++;
	}
	return (str);
}

/*
int	main(void)
{
//	char	source[] = "Source string.";
	char	source[] = "SOURCE STRING.";
	char	*dest;
	
	printf("\tsource: %s\n", source);
	dest = ft_strlowcase(source);
	printf("\toutcome: %s\n", dest);
	return (0);
}
*/
