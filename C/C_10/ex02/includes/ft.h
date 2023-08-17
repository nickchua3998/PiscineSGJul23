/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:38:52 by hchua             #+#    #+#             */
/*   Updated: 2023/08/11 13:38:56 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	display_error(char *prog_name, char *file_name);

int		ft_atoi(char *str);

int		ft_strcmp(char *s1, char *s2);

int		ft_strlen(char *str);

int		ft_str_is_numeric(char *str);

int		ft_tail_error(int argc, char **argv);

int		ft_file_error(int fd, char *buffer, char *program, char *file);

int		ft_tail_iterate(char *buffer, int fd, int index, int bytes_to_show);

int		ft_tail(char *program, char *file, int bytes_to_show);

#endif
