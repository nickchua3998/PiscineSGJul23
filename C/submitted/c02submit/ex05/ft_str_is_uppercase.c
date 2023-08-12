/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:36 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 15:02:35 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	c;
	int	outcome;

	outcome = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 'A') || (str[c] > 'Z'))
			outcome = 0;
		c++;
	}
	return (outcome);
}

/*
int	main(void)
{
//	char	teststr[] = "AlPhAbEtS";
	char	teststr[] = "ALPHABETS";
	int	outcome;

	outcome = ft_str_is_uppercase(teststr);

	printf("teststr : %d\n", outcome);
}
*/
