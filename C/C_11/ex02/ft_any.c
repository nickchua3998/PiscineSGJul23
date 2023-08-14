/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:53:16 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 11:53:19 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
	char *tab[5] = {"h", "g", "f", "d", '\0'};


//		printf("%s\n", tab[i]);
		printf("%d\n", ft_any(tab, &ft_if_int));
}
*/
