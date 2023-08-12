/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-leary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:34:04 by so-leary          #+#    #+#             */
/*   Updated: 2023/08/08 15:28:08 by so-leary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	is_token(char *str, char *charset, int i)
{
	if (str[i] != '\n' && !is_separator(str[i], charset))
		if (i == 0 || is_separator(str[i - 1], charset))
			return (-1);
	if (is_separator(str[i], charset) || str[i] == '\0')
		if (i > 0 && !is_separator(str[i - 1], charset))
			return (1);
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*get_token(char *str, int t0, int t1)
{
	char	*token;

	token = ft_strncpy(
			(char *)malloc((t1 - t0 + 1) * sizeof(char)),
			str + t0, t1 - t0);
	return (token);
}

char	**ft_split(char *str, char *charset)
/*
Create a function that splits a string of character depending on
	another string of characters.

You’ll have to use each character from the string charset as a separator.

The function returns an array where each element of the array
contains the address of a string wrapped between two separators. The last
element of that array should equal to 0 to indicate the end of the array.

There cannot be any empty strings in your array. Get your own conclusions ac-
cordingly.

The string given as argument won’t be modifiable.

Here’s how it should be prototyped :
	char **ft_split(char *str, char *charset);
*/
{
	int		i;
	int		j;
	int		t0;
	int		tokens;
	char	**str_split;

	i = -1;
	tokens = 0;
	while (str[++i])
		if (is_token(str, charset, i) == -1)
			tokens++;
	str_split = (char **)malloc((tokens + 1) * sizeof(char *));
	i = -1;
	j = -1;
	while (++i >= 0)
	{
		if (is_token(str, charset, i) == -1)
			t0 = i;
		else if (is_token(str, charset, i) == 1 && t0 <= i)
			str_split[++j] = get_token(str, t0, i);
		if (str[i] == '\0')
			break ;
	}
	str_split[j + 1] = 0;
	return (str_split);
}

/*TEST
#include <stdio.h>
#include <string.h>

void	test(char	*input_1, char *input_2)
{
	printf("%s | %s -->\n", input_1, input_2);
	char **actual = ft_split(input_1, input_2);
	int	i = 0;
	while (actual[i])
	{
		printf("\t%s$\n", actual[i]);
		i++;
	}
	i = 0;
	while (actual[i])
	{
		free(actual[i]);
		i++;
	}
	free(actual);
}

int	main(void)
{
	test("Hello World;how;are;you?", " ;");
	test("some-file-name.xyz", "-");
	test("some-file-name.xyz", "-.");
	test("some-file-name.xyz", "-.");
	test("separated/by+slash=and>plus", "-.");
	test("separated/by+slash=and>plus", "/+=>");
	test("string--with---many-----delimiters", "-");
	test(";;;;;;;;;;", ";");
	test("NoDelimiters", ";");
	test("-leadingsep", "-");
	test("trailingsep-", "-");
}
TEST*/
