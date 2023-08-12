/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:39:52 by hchua             #+#    #+#             */
/*   Updated: 2023/07/30 11:39:59 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (i < n - 1) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	source1[] = "Source string.";
	char	source2[] = "Source ";
	int	result;

	result = ft_strncmp(source1, source2, 16);
	printf("src1: %s\nsrc2: %s\nresult: %d\n", source1, source2, result);
	return (0);
}
*/
/*
       The strncmp() function is similar (to strcmp() - ex00), except it 
       compares  only  the  first (at most) n bytes of s1 and s2.
*/
