/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:59:14 by hchua             #+#    #+#             */
/*   Updated: 2023/08/11 14:59:56 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_tail_iterate(char *buffer, int fd, int index, int bytes_to_show)
{
	int	count;
	int	total_read;

	total_read = 0;
	count = read(fd, &buffer[index], bytes_to_show - index);
	while (count > 0)
	{
		total_read += count;
		if (count < bytes_to_show - index)
			index += count;
		else
			index = 0;
		count = read(fd, &buffer[index], bytes_to_show - index);
	}
	if (count == -1)
		return (1);
	if (total_read < bytes_to_show)
		write(1, buffer, total_read);
	else
	{
		write(1, &buffer[index], bytes_to_show - index);
		write(1, buffer, index);
	}
	return (0);
}

int	ft_tail(char *program, char *file, int bytes_to_show)
{
	char	*buffer;
	int		fd;
	int		index;

	buffer = malloc(bytes_to_show);
	if (!buffer)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_file_error(fd, buffer, program, file));
	index = 0;
	if (ft_tail_iterate(buffer, fd, index, bytes_to_show))
		return (ft_file_error(fd, buffer, program, file));
	free(buffer);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	bytes_to_show;
	int	i;
	int	exit_code;

	if (ft_tail_error(argc, argv))
		return (1);
	bytes_to_show = ft_atoi(argv[2]);
	i = 3;
	exit_code = 0;
	while (i < argc)
	{
		if (argc > 4 && open(argv[i], O_RDONLY) != -1)
		{
			if (i >= 4)
				write(2, "\n", 1);
			write(2, "==> ", 4);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, " <==\n", 5);
		}
		exit_code += ft_tail(argv[0], argv[i], bytes_to_show);
		i++;
	}
	return (exit_code > 0);
}
