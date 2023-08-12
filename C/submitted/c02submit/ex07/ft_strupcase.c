/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:17:47 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 15:19:39 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 97) && (str[c] <= 122))
			str[c] -= 32;
		c++;
	}
	return (str);
}

/*
int	main(void)
{
	char	source[] = "Source string.";
//	char	source[] = "SOURCE STRING.";
	char	*dest;
	
	printf("\tsource: %s\n", source);
	dest = ft_strupcase(source);
	printf("\toutcome: %s\n", dest);
	return (0);
}
*/
