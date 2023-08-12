/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:29:07 by hchua             #+#    #+#             */
/*   Updated: 2023/08/03 14:29:18 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)

{
	char	*dest;
	int		s;

	dest = malloc(ft_strlen(src) + 1);
	s = 0;
	if (dest == NULL)
		return (0);
	else
	{
		while (src[s])
		{
			dest[s] = src[s];
			s++;
		}
		dest[s] = '\0';
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	source[] = "Source string.";
	char	*dest;

	dest = ft_strdup(source);
	printf("src: %s\ndes: %s\n", source, dest);
	return (0);
}
*/
/*
       The  strdup() function returns a pointer to a new string which is a du‐
       plicate of the string s.  Memory for the new string  is  obtained  with
       malloc(3), and can be freed with free(3).
       
       On  success,  the strdup() function returns a pointer to the duplicated
       string.  It returns NULL if insufficient memory was available, with er‐
       rno set to indicate the cause of the error.
       
       The malloc() function allocates size bytes and returns a pointer to the
       allocated  memory.   The memory is not initialized.  If size is 0, then
       malloc() returns either NULL, or a unique pointer value that can  later
       be successfully passed to free().

       The  free()  function  frees  the memory space pointed to by ptr, which
       must have been returned by a previous call to  malloc(),  calloc(),  or
       realloc().   Otherwise, or if free(ptr) has already been called before,
       undefined behavior occurs.  If ptr is NULL, no operation is performed.

*/
