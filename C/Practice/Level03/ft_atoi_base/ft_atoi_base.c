/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:47:42 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 21:47:45 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int	read_base(char c, char *base)
{
	int	i;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
}

int	ft_atoi_base(const char *str, int str_base)
{




}
