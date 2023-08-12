/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_is_lowercase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:55:00 by hchua             #+#    #+#             */
/*   Updated: 2023/07/28 14:58:16 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	c;
	int	outcome;

	outcome = 1;
	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 'a') || (str[c] > 'z'))
			outcome = 0;
		c++;
	}
	return (outcome);
}

/*
int	main(void)
{
	char	teststr[] = "AlPhAbEtS";
//	char	teststr[] = "alphabets";
	int	outcome;

	outcome = ft_str_is_lowercase(teststr);

	printf("teststr : %d\n", outcome);
}
*/
