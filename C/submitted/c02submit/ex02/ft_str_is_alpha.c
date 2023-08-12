/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:27:44 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 13:51:36 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	c;
	int	outcome;

	outcome = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 'A') || (str[c] > 'Z' && str[c] < 'a') || (str[c] > 'z'))
			outcome = 0;
		c++;
	}
	return (outcome);
}

/*
int	main(void)
{
//	char	teststr[] = "AlPhAbEtS";
	char	teststr[] = "123890";
	int	outcome;
	
	outcome = ft_str_is_alpha(teststr);

	printf("teststr : %d\n", outcome); 
}
*/
