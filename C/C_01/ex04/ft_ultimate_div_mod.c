/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:36:45 by hchua             #+#    #+#             */
/*   Updated: 2023/07/27 22:36:58 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
int	main(void)
{
	int	a, b, *ptr1, *ptr2;

	a = 11;
	b = 3;
	ptr1 = &a;
	ptr2 = &b;
	
	printf("Before function, a = %d\n", a);
	printf("Before function, b = %d\n\n", b);
	
	ft_ultimate_div_mod(ptr1, ptr2);
	printf("Division result aka a = %d\n", a);
	printf("Modulus result aka b = %d\n", b);
}
*/
