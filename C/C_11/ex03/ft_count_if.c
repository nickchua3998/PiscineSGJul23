/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:06:07 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 12:06:10 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			n++;
		i++;
	}
	return (n);
}
/*
int	ft_if_int(char *a)
{
	if ( *a >= '0' && *a <= '9')
		return (*a - 48);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int i = 0;
	char *tab[5] = {"h", "1", "8", "d", "7"};


//		printf("%s\n", tab[i]);
		printf("%d\n", ft_count_if(tab, 5, &ft_if_int));
}
*/
