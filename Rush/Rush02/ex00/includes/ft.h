/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:41:21 by hchua             #+#    #+#             */
/*   Updated: 2023/08/09 16:42:41 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	unsigned long long int		nb;
	char						*val;
}	t_list;
unsigned long long int	get_10mult(unsigned long long int nb);
unsigned long long int	get_mult(unsigned long long int nb);
unsigned long long int	ft_atoi(const char *str);

void					ft_putchar(char c);
void					ft_putstr(char *str);
char					*ft_strdup(char *src);
char					*get_index_num(int dict);
char					*get_writestr(int dict, char *c);
t_list					*extract_tab(char *file);
int						ft_atoi_sign(const char *str);

#endif
