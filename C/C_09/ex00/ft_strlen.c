/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:57:13 by hchua             #+#    #+#             */
/*   Updated: 2023/07/27 20:57:35 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

/*
int	main(void)
{
	char	str[] = "Hello, world!";
	char	*p_str;
	int	count;

	p_str = str;
	count = ft_strlen(p_str);
	printf("Length of string = %d\n",count);
	return (0);
}
*/
