/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:59:11 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 19:59:14 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	do_op(int n1, int n2, char ops)
{
	if (( ops == '/' || ops == '%') && (n2 == 0))
	{	
		ft_putstr("Stop : division / modulo by zero\n");
		exit (1);
	}
	else if (ops == '+')
		return (ft_add(n1, n2));
	else if (ops == '-')
		return (ft_minus(n1, n2));
	else if (ops == '*')
		return (ft_mul(n1, n2));
	else if (ops == '/')
		return (ft_div(n1, n2));
	else if (ops == '%')
		return (ft_mod(n1, n2));
}

int	main(int argc, char **argv)
{
	char	op;
	int	n1;
	int	n2;

	if (argc != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	op = argv[2][0];
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	ft_putnbr(do_op(n1, n2, op));
	ft_putchar('\n');
}
