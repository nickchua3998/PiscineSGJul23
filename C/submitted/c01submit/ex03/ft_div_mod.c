/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:55:17 by hchua             #+#    #+#             */
/*   Updated: 2023/07/27 20:09:37 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

/*
void	main(void)
{
	int	a, b, div, mod, *ptr1, *ptr2;

	a = 11;
	b = 3;
	ptr1 = &div;
	ptr2 = &mod;
	
	ft_div_mod(a, b, ptr1, ptr2);

	printf("Division result = %d\n", div);
	printf("Modulus result = %d\n", mod);
}
*/
