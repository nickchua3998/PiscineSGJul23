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

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		s;
	int		f;
	char	*ptr;

	s = 0;
	f = 0;
	if (to_find[f] == '\0')
		return (str);
	while (str[s] != '\0')
	{
		if (str[s] == to_find[f])
		{
			ptr = str + s;
			while (str[s] != '\0' && str[s] == to_find[f])
			{
				s++;
				f++;
				if (to_find[f] == '\0')
					return (ptr);
			}
			f = 0;
		}
		s++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str = "Destination of the source string";
	char	*to_find = "";
	
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
