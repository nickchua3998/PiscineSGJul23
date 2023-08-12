/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:47:51 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/07 14:34:07 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
/*
Reproduce the behavior of the function strdup (man strdup).

Here’s how it should be prototyped :
	char *ft_strdup(char *src);
*/
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*TEST
#include <stdio.h>
#include <string.h>

void	test(char	*input_1)
{
	char	color[] = "\033[31m";
	char	comparator[] = "!=";
	char	result[] = "FAIL";

	char*	actual = ft_strdup(input_1);
	char* expected = strdup(input_1);
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

	free(actual);
	free(expected);
}

int	main(void)
{
	test("");
	test(" ");
	test("Hello World");
	test("012345678");
}
TEST*/
