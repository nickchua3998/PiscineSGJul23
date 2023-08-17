/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:59:47 by hchua             #+#    #+#             */
/*   Updated: 2023/08/17 20:00:01 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int	ft_atoi(const char *str);
int	ft_add(int a, int b);
int	ft_minus(int a, int b);
int	ft_mul(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);
int	do_op(int n1, int n2, char ops);


#endif
