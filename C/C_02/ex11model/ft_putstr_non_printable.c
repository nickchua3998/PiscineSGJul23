/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:25:28 by jakong            #+#    #+#             */
/*   Updated: 2023/08/02 23:18:20 by jakong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Take char 'A' as example, 'A' in ASCII is 65 in decimal*/
/*Decimal 65 needs to be converted to Hexadecimal*/
/*There 65 / 16 = 4 and 65 % 16 = 1, so HEX = 41*/
/*Hex only got 16 char which start from 0 to 9 and a to f*/
/*Hex is a base of 16*/
/*	int		firstdigit;
	int		seconddigit;
	char	hexdigits[20];
	strcpy(hexdigits, "0123456789abcdef");
	firstdigit = c / 16;
	seconddigit = c % 16;
	ft_putchar('\\');
	ft_putchar(hexdigits(firstdigit));
	ft_putchar(hexdigits(seconddigit));
	c is '\n', its ASCII value is 10 (0x0A). 10 / 16 = 0, in arrary, it's 0.
	10 % 16 = 10, element at index 10 in array "0123456789abcdef" is 'a.
	displays \0a, = hexadecimal representation of the newline character.
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printhex(char c)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str < ' ') || (*str > '~'))
			ft_printhex(*str);
		else
			ft_putchar(*str);
		str++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "Coucou\ntu vas bien";
	printf("Original: %s\n", str);
	printf("Modified: \n");
	ft_putstr_non_printable(str);
	//printf("\n");
	return (0);
}*/
