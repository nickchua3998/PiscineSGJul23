/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:05:22 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 15:09:41 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	c;
	int	outcome;

	outcome = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 32) || (str[c] > 126))
			outcome = 0;
		c++;
	}
	return (outcome);
}

/*
int	main(void)
{
	char	teststr[] = "This is printable SURELY";
//	char	teststr[] = "";
	int	outcome;

	outcome = ft_str_is_printable(teststr);

	printf("teststr : %d\n", outcome);
}
*/
