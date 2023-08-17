/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weichen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:23:17 by weichen           #+#    #+#             */
/*   Updated: 2023/07/29 12:44:07 by weichen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		if (*(tab + i) <= *(tab + i + 1))
		{
			i++;
		}
		else
		{
			j = i;
			while (j >= 0 && *(tab + j) > *(tab + j + 1))
			{
				swap(tab + j, tab + j + 1);
				j--;
			}
			i++;
		}
	}
}
