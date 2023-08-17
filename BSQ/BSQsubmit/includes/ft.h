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
# include <stdio.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);
int		is_char_sep(char c, char *charset);
int		count_addr(char *str, char *charset);
void	copy_addr(char *dest, char *src, char *charset);
void	insert_addr(char **addrlist, char *str, char *charset);
char	**ft_split(char *str, char *charset);

int		map_eof_is_valid(char *mapfile, int *mdepth, int *mwidth, char *eof);
char	**extract_map_tab(char *mapfile, int *mdepth, int *mwidth, char *eof);

char	**ft_gen_map(int depth, int width);
int		is_eof(char c, char *charset);

int		solve_largestsq(char *map_name);
int		ft_min(int a, int b, int c);
int		**ft_generate_map(int l, int c);
int		ft_biggest_square(char **map, int c, int l, char o);
int		ft_find_posn_sq(char **map, int *mwidth, int *mdepth, char *obst);
char	**ft_fill_map(char **map, int c, int l, char *eof);

#endif
