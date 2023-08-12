/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:49:10 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 18:49:17 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	s;
	unsigned int	catlen;

	d = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	while (dest[d] != '\0' && d < size)
		d++;
	catlen = d + s;
	if (d == size)
		return (catlen);
	else
	{	
		s = 0;
		while (src[s] != '\0' && d < (size - 1))
		{
			dest[d] = src[s];
			d++;
			s++;
		}
		dest[d] = '\0';
	}
	return (catlen);
}
/*
int	main(void)
{
	char	src[] = "Source string.";
	char	dest[100] = "Dest: ";
	int	size = 20;
	int	count;

	count = ft_strlcat(dest, src, size);
	printf("src: %s\ndes: %s\nsize: %d\ncount: %d\n", src, dest, size, count);
	if (count >= size)
		printf("Truncation occurred\n");
	else
		printf("String cat is successful\n");
	return (0);
}
*/
/*
     The strlcat() function appends the NUL-terminated string src to the end
     of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
     nating the result.

     The strlcat() function returns the total length of the string it tried 
     to create. For strlcat() that means the initial length of dst plus the 
     length of src.

     Note, however, that if strlcat() traverses size characters without find‐
     ing a NUL, the length of the string is considered to be size and the des‐
     tination string will not be NUL-terminated (since there was no space for
     the NUL).  This keeps strlcat() from running off the end of a string.  In
     practice this should not happen (as it means that either size is incor‐
     rect or that dst is not a proper “C” string).  The check exists to pre‐
     vent potential security problems in incorrect code.
*/
