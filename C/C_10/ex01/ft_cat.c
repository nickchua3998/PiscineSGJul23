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

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);

void	handle_error(char *program_name, char *filename)
{
	ft_putstr(program_name, STDERR_FD);
	ft_putstr(": ", STDERR_FD);
	ft_putstr(filename, STDERR_FD);
	ft_putstr(": ", STDERR_FD);
	perror(NULL);
}

int	ft_read_file(char *filepath)
{
	char	buf[BUFF_SIZE];
	int		file;
	int		bytes_read;

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		bytes_read = read(file, buf, BUFF_SIZE);
		while (bytes_read > 0)
		{
			write(STDOUT_FD, buf, bytes_read);
			bytes_read = read(file, buf, BUFF_SIZE);
		}
		close(file);
		return (1);
	}
	else
		return (0);
}

void	no_args_handling(char *program_name)
{
	char	buf;

	while (read(STDIN_FD, &buf, 1) != 0)
		ft_putchar(buf, STDOUT_FD);
	if (errno != 0)
		handle_error(program_name, "stdin");
}

int	main(int argc, char **argv)
{
	char	*program_name;
	int		i;

	program_name = basename(argv[0]);
	if (argc == 1)
		no_args_handling(program_name);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_read_file(argv[i]))
				handle_error(program_name, argv[i]);
			i++;
		}
	}
	return (0);
}
