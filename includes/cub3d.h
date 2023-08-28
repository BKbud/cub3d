/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:28:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/25 16:52:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "parsing.h"
# include "vec.h"
# include "player.h"

# define W_X 1200
# define W_Y 1200
# define FOV 60
# define EPS 1e-06
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_KEY_EXIT 17
# define KEY_SPACE 49
# define KEY_ESC 53
# define MAP_SCALE 10

typedef struct s_texture {
	void				*img;
	unsigned int		*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}	t_texture;

typedef struct s_data
{
	t_game		*game;
	t_player	player;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_texture	*n_tex;
	t_texture	*s_tex;
	t_texture	*e_tex;
	t_texture	*w_tex;
	t_texture	*cd_tex;
}	t_data;

typedef struct s_cpoint
{
	t_vec2	pos;
	char	c_dir;
	int		door_flag;
}	t_cpoint;

void		raycast(t_player *player, t_game *game, t_data *data);
t_cpoint	raycast_single(t_vec2 pos, t_vec2 dir, t_game *game);
t_vec2		rotate_ray_h(t_vec2 p_dir, int i);
void		draw_wall(t_player *player, t_game *game, t_data *data, int index);
t_cpoint	raycast_single_step_x(t_vec2 pos, t_vec2 dir, t_game *game);
t_cpoint	raycast_single_step_y(t_vec2 pos, t_vec2 dir, t_game *game);
double		deg2rad(double deg);
int			is_zero(double d);

void		init_tex_wall(t_data *data, t_game *game);
t_texture	*new_tex(t_data *data, char *filename);
int			get_tex_col(t_cpoint inter, t_texture *tex);
int			get_tex_color(t_data *data, t_cpoint inter, int wy, int wheight);
void		open_door(t_data *data);
void		close_door(t_data *data);

void		minimap(t_player *player, t_game *game, t_data *data);

#endif