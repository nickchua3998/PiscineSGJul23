/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:59:34 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 15:59:43 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d;
	unsigned int	s;

	d = 0;
	s = 0;
	while (dest[d] != '\0')
		d++;
	while (src[s] != '\0' && s < nb)
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
	printf("result: %s\n", ft_strncat(dest, src, 8));
	return (0);
}
*/
/*
	The strncat() function is similar, except that
   	*  it will use at most n bytes from src; and
   	*  src need not be null-terminated if it contains n or more bytes.
   
	The strncat() function is always null-terminted.  
       
       If src contains n or more bytes, strncat() writes n+1 bytes to dest  (n
       from  src plus the terminating null byte).  Therefore, the size of dest
       must be at least strlen(dest)+n+1.

*/
