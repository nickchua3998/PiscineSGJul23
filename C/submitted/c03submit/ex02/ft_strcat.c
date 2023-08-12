/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:01:06 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 14:01:13 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

/*
int	main(void)
{
	char	*src = " destination.";
	char	dest[100] = "Source string";
	
	printf("src: %s\ndest: %s\n", src, dest);
	printf("result: %s\n", ft_strcat(dest, src));
	return (0);
}
*/
/*
       The  strcat() function appends the src string to the dest string, over‐
       writing the terminating null byte ('\0') at the end of dest,  and  then
       adds  a  terminating  null  byte.  
       
       The strings may not overlap, and the dest string must have enough space
       for the  result.
       
       The strcat() function returns a pointer to the resulting string dest.
*/
