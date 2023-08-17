/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:54:54 by hchua             #+#    #+#             */
/*   Updated: 2023/07/27 12:00:31 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 20;
	printf("Values of a and b before swap are %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("Values of a and b after swap are %d %d\n", a, b);
	return (0);
}
*/
