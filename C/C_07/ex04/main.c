
#include <stdio.h>

int	parse_for_string(int argc, char **argv, char *str);
int	parse_for_base(int argc, char **argv, char *bf, char *bt);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	inputstr[100];
	char	basef[100];
	char	baset[100];

	parse_for_string(argc, argv, inputstr);
	parse_for_base(argc, argv, basef, baset);
	printf("Outputstring = %s\n", ft_convert_base(inputstr, basef, baset));
}
/*
int	main(void)
%
{
	printf("%s\n", ft_convert_base(" \t \n7FFFFFFF", "0123456789ABCDEF", "0123456789"));
	printf("%s\n", ft_convert_base(" \n 2147483647", "0123456789", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base(" \r -80000000", "0123456789ABCDEF", "0123456789"));
	printf("%s\n", ft_convert_base(" \r -2147483648", "0123456789", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base(" +12 \t", "0123456789", "01"));
	printf("%s\n", ft_convert_base("-1100", "01", "0123456789"));
	printf("%s\n", ft_convert_base("+32", "0123456789", "01234567"));
}
*/
