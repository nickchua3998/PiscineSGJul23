/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:30:42 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 16:30:46 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*t;

	while (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		s = str;
		t = to_find;
		while (*s != '\0' && *t != '\0' && *s == *t)
		{
			s++;
			t++;
		}
		if (*t == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Destination of the source string";
	char	*to_find = "nation";
	
	printf("src: %s\nfind: %s\n", str, to_find);
	printf("result: %s\n", ft_strstr(str, to_find));
	return (0);
}
*/
/*
       The  strstr() function finds the first occurrence of the substring nee‐
       dle in the string haystack.  The terminating null bytes ('\0') are  not
       compared.
       
       These functions return a pointer to the beginning of the  located  sub‐
       string, or NULL if the substring is not found.     
*/
