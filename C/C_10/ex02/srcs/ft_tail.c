/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:04:10 by hchua             #+#    #+#             */
/*   Updated: 2023/08/10 18:04:23 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		++str;
	if (*str == '-')
		neg = -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

void	display_error(char *prog_name, char *file_name)
{
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int	ft_tail_error(int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "-c") == 0)
	{
		write(2, "./", 2);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": option requires an argument -- 'c'\n", 37);
		return (1);
	}
	else if (argc > 2 && ft_strcmp(argv[1], "-c") == 0
		&& !ft_str_is_numeric(argv[2]))
	{
		write(2, "./", 2);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": invalid number of bytes: '", 28);
		write(2, argv[2], ft_strlen(argv[2]));
		write(2, "'\n", 2);
		return (1);
	}
	else if (argc < 4 || ft_strcmp(argv[1], "-c") != 0)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " -c <number> <file>\n", 20);
		return (1);
	}
	return (0);
}

int	ft_file_error(int fd, char *buffer, char *program, char *file)
{
	display_error(program, file);
	free(buffer);
	close(fd);
	return (1);
}
