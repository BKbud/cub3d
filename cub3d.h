/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:28:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/21 19:11:43 by hanryu           ###   ########.fr       */
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

# define WINDOW_X 400
# define WINDOW_Y 250
# define FOV 60
# define FOV_H FOV*(M_PI/180)
# define FOV_V (FOV_H*(double)WINDOW_Y/(double)WINDOW_X)

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
}	t_player;

#endif