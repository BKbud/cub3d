/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:51:22 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:51:33 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < W_X) && (0 <= y && y < W_Y))
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	wall_pixel(double d)
{
	double	fov_h;

	fov_h = 2.0 * d * tan(((deg2rad(FOV) * (double)W_Y / (double)W_X)) / 2.0);
	return ((int)(W_Y / fov_h));
}

void	draw_wall(t_player *player, t_game *game, t_data *data, int index)
{
	int		wpixel;
	int		y_start;
	int		y_end;
	int		j;
	double	theta;

	//raycasting 진행
	t_cpoint	inter = raycast_single(player->pos, rotate_ray_h(player->dir, index + 1), game);

	theta = (deg2rad(FOV) / (W_X - 1)) * (index + 1 - ((double)(W_X + 1) / 2)); // 어안렌즈 왜곡 보정
	wpixel = wall_pixel(vec_dis(inter.pos, player->pos) * cos(theta));
	y_start = (W_Y - wpixel) / 2;
	y_end = ((W_Y + wpixel) / 2) - 1;
	j = 0;
	while (j < W_Y)
	{
		if (j < y_start)
		{
			//draw sky
			my_mlx_pixel_put(data, index, j, create_rgb(game->c_color->red, game->c_color->green, game->c_color->blue));
		}
		else if (y_end < j)
		{
			//draw floor
			my_mlx_pixel_put(data, index, j, create_rgb(game->f_color->red, game->f_color->green, game->f_color->blue));
		}
		else
		{
			//draw wall
			my_mlx_pixel_put(data, index, j, create_rgb(0x80, 0x80, 0x80));
		}
		j++;
	}
}
