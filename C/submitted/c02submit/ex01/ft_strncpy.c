/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:28:02 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 11:36:13 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (c < n && src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{	
		dest[c] = '\0';
		c++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	source[] = "Source string.";
	char	destin[] = "Destination string.";
	char	*dest;

	printf("BEFORE\n\tsrc: %s\n\tdes: %s\n", source, destin);

	dest = ft_strncpy(destin, source, 8);

	printf("AFTER\n\tsrc: %s\n\tdes: %s\n", source, dest);
	return (0);
}
*/
/*
The  strncpy()  function is similar, except that at most n bytes of src
are copied.  Warning: If there is no null byte among the first n  bytes 
of src, the string placed in dest will not be null-terminated.

If  the  length of src is less than n, strncpy() writes additional null
bytes to dest to ensure that a total of n bytes are written.
*/
