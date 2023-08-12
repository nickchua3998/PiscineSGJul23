/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:27:46 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 14:29:14 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	c;
	int	outcome;

	outcome = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < '0') || (str[c] > '9'))
			outcome = 0;
		c++;
	}
	return (outcome);
}

/*
int	main(void)
{
	char	teststr[] = "123 456 789";
//	char	teststr[] = "123890";
	int	outcome;
	
	outcome = ft_str_is_numeric(teststr);

	printf("teststr : %d\n", outcome);
}
*/
