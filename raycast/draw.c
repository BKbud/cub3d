/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:51:22 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/28 13:48:01 by hanryu           ###   ########.fr       */
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

static void	draw_wall2(t_game *game, t_data *data, t_cpoint inter, int arr[3])
{
	int	y_start;
	int	y_end;
	int	index;
	int	j;

	y_start = arr[0];
	y_end = arr[1];
	index = arr[2];
	j = 0;
	while (j < W_Y)
	{
		if (j < y_start)
			my_mlx_pixel_put(data, index, j, create_rgb(game->c_color->red,
					game->c_color->green, game->c_color->blue));
		else if (y_end < j)
			my_mlx_pixel_put(data, index, j, create_rgb(game->f_color->red,
					game->f_color->green, game->f_color->blue));
		else
			my_mlx_pixel_put(data, index, j,
				get_tex_color(data, inter, j - y_start, y_end - y_start));
		j++;
	}
}

void	draw_wall(t_player *player, t_game *game, t_data *data, int index)
{
	int			wpixel;
	int			arr[3];
	double		theta;
	t_cpoint	inter;

	inter = raycast_single(player->pos,
			rotate_ray_h(player->dir, index + 1), game);
	theta = (deg2rad(FOV) / (W_X - 1))
		* (index + 1 - ((double)(W_X + 1) / 2));
	wpixel = wall_pixel(vec_dis(inter.pos, player->pos) * cos(theta));
	arr[0] = (W_Y - wpixel) / 2;
	arr[1] = ((W_Y + wpixel) / 2) - 1;
	arr[2] = index;
	draw_wall2(game, data, inter, arr);
}
