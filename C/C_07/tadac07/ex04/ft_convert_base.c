/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:09:51 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/08 12:31:42 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		is_base_valid(char *base);

unsigned int	compute_base_len(char *base)
{
	unsigned int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	return (base_len);
}

void	append_char(char *str, char c)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

void	ft_putnbr_base_recursive(
		unsigned int integer, char *base, char *str, unsigned int *str_len
	)
{
	unsigned int	base_len;

	base_len = compute_base_len(base);
	if (integer >= base_len)
	{
		ft_putnbr_base_recursive(integer / base_len, base, str, str_len);
		ft_putnbr_base_recursive(integer % base_len, base, str, str_len);
	}
	else
	{
		*str_len = *str_len + 1;
		append_char(str, base[integer]);
	}
}

char	*ft_itoa_base(int integer, char *base, char *str, unsigned int *str_len)
{
	unsigned int		base_len;

	*str_len = 1;
	base_len = compute_base_len(base);
	if (integer < 0)
	{
		*str_len = *str_len + 1;
		append_char(str, '-');
		ft_putnbr_base_recursive((unsigned int)-integer, base, str, str_len);
	}
	else if ((unsigned int)integer >= base_len)
		ft_putnbr_base_recursive((unsigned int)integer, base, str, str_len);
	else
	{
		*str_len = *str_len + 1;
		append_char(str, base[integer]);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
/*
Create a function that returns the result of the conversion of
	the string nbr from a base base_from to a base base_to.

nbr, base_from, base_to may be not writable.

nbr will follow the same rules as ft_atoi_base (from an other module).
	Beware of ’+’, ’-’ and whitespaces.

The number represented by nbr must fit inside an int.

If a base is wrong, NULL should be returned.

The returned number must be prefix only by a single and uniq ’-’ if necessary,
no whitespaces, no ’+’.

Here’s how it should be prototyped :
	char *ft_convert_base(char *nbr, char *base_from, char *base_to);
*/
{
	int				integer;
	char			*nbr_converted;
	unsigned int	i;
	unsigned int	nbr_converted_len;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (0);
	integer = ft_atoi_base(nbr, base_from);
	nbr_converted_len = 0;
	ft_itoa_base(integer, base_to, 0, &nbr_converted_len);
	nbr_converted = (char *)malloc((nbr_converted_len) * sizeof(char));
	if (nbr_converted == 0)
		return (0);
	i = -1;
	while (++i < nbr_converted_len)
		nbr_converted[i] = '\0';
	ft_itoa_base(integer, base_to, nbr_converted, &nbr_converted_len);
	return (nbr_converted);
}

/*TEST
#include <stdio.h>
#include <string.h>

void	test(char	*input_1, char *input_2, char *input_3, char *expected)
{
	char	color[] = "\033[31m";
	char	comparator[] = "!=";
	char	result[] = "FAIL";

	char*	actual = ft_convert_base(input_1, input_2, input_3);
	if (strcmp(actual, expected) == 0)
	{
		comparator[0] = '=';
		strcpy(result, "PASS");
		strcpy(color, "\033[32m");
	}

	printf(
			"[%s%s\033[0m] %s --> %s %s %s\n",
			color,
			result,
			input_1,
			actual,
			comparator,
			expected
		);
	if (actual)
		free(actual);
}

int	main(void)
{
	test("42", "0123456789", "01", "101010");
	test("-42", "0123456789", "01", "-101010");
	test("2147483647", "0123456789", "01", "1111111111111111111111111111111");
	test("42", "0123456789", "0123456789abcdef", "2a");
	test("2a", "0123456789abcdef", "0123456789", "42");
	test("2a", "0123456789abcdef", "01", "101010");
	test("-2147483647", "0123456789", "01", "-1111111111111111111111111111111");
	test("-----789", "0123456789", "01", "-1100010101");
}
TEST*/
