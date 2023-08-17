/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:01:03 by hchua             #+#    #+#             */
/*   Updated: 2023/08/10 18:01:17 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 30000
#define STDIN_FD 0
#define STDOUT_FD 1
#define STDERR_FD 2

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void	ft_putstr(char *str, int out)
{
	write(out, str, strlen(str));
}
