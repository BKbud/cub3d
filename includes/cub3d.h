/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:48:06 by bojung            #+#    #+#             */
/*   Updated: 2023/07/24 17:48:07 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_color {
	int	red;
	int	blue;
	int	green;
}	t_color;

typedef struct s_game {
	void	*mlx;
	void	*win;
	size_t	hei;
	size_t	wid;
	char	**map;
	char	*n_texure;
	char	*s_texure;
	char	*e_texure;
	char	*w_texure;
	t_color	*f_color;
	t_color	*c_color;
}	t_game;

// mapset.c
void 	read_map(char *filename, t_game *game);
void	check_max_wid(t_game *game, char *line, int fd);
void	init_map(t_game *game, int fd, char *filename);
char	*jump_to_map(t_game *game, int fd);

// map_utils.c
int		is_space(char c);
char	*get_valid_line(int fd);
char	*erase_space(char *line);
void	space_adder(t_game *game, char *map, char *line);
void	init_game(t_game *game);

// information_set.c
char	*type_identifier(t_game *game, int fd);
int		set_data(t_game *game, char *line);
t_color	*set_color(char *line);

// err_handler.c
void	check_extension(char *filename);
void	print_err(char *msg, t_game *game);
void	check_init_data(t_game *game);
void	exit_game(t_game *game);


#endif
