/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:48:06 by bojung            #+#    #+#             */
/*   Updated: 2023/08/23 16:57:12 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define TRUE 1
# define BUFFER_SIZE 10

typedef struct s_color {
	int	red;
	int	blue;
	int	green;
}	t_color;

typedef struct s_flags
{
	int	e_flag;
	int	w_flag;
	int	s_flag;
	int	n_flag;
	int	f_flag;
	int	c_flag;
	int	d_flag;
	int	door_flag;
}	t_flags;

typedef struct s_game {
	size_t	hei;
	size_t	wid;
	char	**map;
	char	direction;
	t_flags	flags;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*cd_texture;
	t_color	*f_color;
	t_color	*c_color;
}	t_game;

// mapset.c
void	read_map(char *filename, t_game *game);
void	check_max_wid(t_game *game, char *line, int fd);
void	init_map(t_game *game, int fd, char *filename);
char	*jump_to_map(int fd);
void	space_adder(t_game *game, char *map, char *line);

// map_utils.c
void	init_game(t_game *game);
int		is_whitespace(char c);
char	*get_valid_line(int fd);
char	*erase_space(char *line);
void	is_valid_code(char *line);

// information_set.c
char	*type_identifier(t_game *game, int fd);
int		set_data(t_game *game, char *line);
t_color	*set_color(char *line);
void	check_color(char *line);
void	set_flags(t_game *game, char *line);

// err_handler.c
void	print_err(char *msg);
void	check_init_data(t_game *game);
void	map_check(t_game *game);
void	validation_check(t_game *game);
void	check_extension(char *filename);

// get_next_line.c
char	*get_next_line(int fd);

#endif
