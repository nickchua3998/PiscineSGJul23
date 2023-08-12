/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:45:54 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 16:47:25 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	c;
	unsigned int	i;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		c++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src [i];
			i++;
		}
		while (i <= size)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (c);
}

/*
int	main(void)
{
	char	source[] = "Source string.";
	char	dest[100];
	int		count;

	count = ft_strlcpy(dest, source, 14);
	printf("src: %s\ndes: %s\nsize: %d\n", source, dest, count);
	return (0);
}
*/

/*
strlcpy() takes the full size of the buffer (not just the length) and 
guarantee to NUL-terminate the result (as long as size is larger than 0)  

Note that a byte for the NUL should be included in size.  Also note that 
strlcpy() only operate on true “C” strings.  This means that for strlcpy() 
src must be NUL-terminated.

The strlcpy() function copies up to size - 1 characters from the NUL-terminated
string src to dst, NUL-terminating the result.

The strlcpy() function return the total length of the string they tried to 
create. For strlcpy() that means the length of src.
(*My assumption without \0 counted)
*/
