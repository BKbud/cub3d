/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:28:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/22 15:44:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>
# include "vec.h"

# define W_X 1000
# define W_Y 1000
# define FOV 60
# define FOV_H FOV*(M_PI/180)
# define FOV_V (FOV_H*(double)W_Y/(double)W_X)
# define EPS (1e-06)
# define is_zero(d) (fabs(d) < EPS)
# define D_X 6
# define D_Y 5

typedef struct s_color {
	int	red;
	int	blue;
	int	green;
}	t_color;

typedef struct s_game {
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
}	t_player;

typedef struct s_cpoint
{
	t_vec2	pos;
	char	c_dir;
}	t_cpoint;

void	raycast(t_player *player, const char map[D_Y][D_X], t_data *data);
void	draw_wall(t_vec2 pos, t_cpoint inter, int index, t_data *data);

#endif