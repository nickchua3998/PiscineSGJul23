/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:26 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 11:09:06 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
int	main(void)
{
	char	source1[] = "Source string.";
	char	source2[] = "Source string. To Destination";
	int	result;

	result = ft_strcmp(source1, source2);
	printf("src1: %s\nsrc2: %s\nresult: %d\n", source1, source2, result);
	return (0);
}
*/
/*
       The  strcmp()  function compares the two strings s1 and s2. 
       The comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as
       follows:
       • 0, if the s1 and s2 are equal;
       • a negative value if s1 is less than s2;
       • a positive value if s1 is greater than s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer less than, equal
       to, or greater than zero if s1 (or the first n bytes thereof) is found,
       respectively, to be less than, to match, or be greater than s2.
*/
