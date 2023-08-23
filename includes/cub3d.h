/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:28:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/23 17:45:17 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "parsing.h"
# include "vec.h"

# define W_X 1500
# define W_Y 1000
# define FOV 60
# define EPS 1e-06

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

void		raycast(t_player *player, t_game *game, t_data *data);
void		draw_wall(t_vec2 pos, t_cpoint inter, int index, t_data *data);
t_cpoint	raycast_single_step_x(t_vec2 pos, t_vec2 dir, t_game *game);
t_cpoint	raycast_single_step_y(t_vec2 pos, t_vec2 dir, t_game *game);
double		deg2rad(double deg);
int			is_zero(double d);

#endif