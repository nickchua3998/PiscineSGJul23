/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:09:44 by hchua             #+#    #+#             */
/*   Updated: 2023/08/12 14:10:15 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_print(unsigned long long int n, t_list *tab, int *first)
{
	unsigned long long int	mult;
	int						i;

	i = 0;
	mult = get_mult(n);
	if (mult >= 100)
		ft_print(n / mult, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (tab[i].nb != mult)
		i++;
	ft_putstr(tab[i].val);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, tab, first);
}

int	use_dict(char *dict, char *argvalue)
{
	unsigned long long int	value;
	int						*first;
	int						addr_first;
	t_list					*tab;

	addr_first = 1;
	first = &addr_first;
	value = ft_atoi(argvalue);
	if (ft_atoi_sign(argvalue) < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	tab = extract_tab(dict);
	ft_print(value, tab, first);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	dictname[100];

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
		use_dict("numbers.dict", argv[1]);
	if (argc == 3)
	{
		i = -1;
		while (argv[1][++i])
			dictname[i] = argv[1][i];
		dictname[i] = '\0';
		use_dict(dictname, argv[2]);
	}
	return (1);
}
