/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:51:22 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/22 15:37:15 by hanryu           ###   ########.fr       */
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

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	wall_pixel(double d)
{
	double	fov_h = 2.0 * d * tan(FOV_V / 2.0);
	return ((int)(W_Y / fov_h));
}

void	draw_wall(t_vec2 pos, t_cpoint inter, int index, t_data *data)
{
	int	wpixel;
	int	y_start;
	int	y_end;
	int	j;

	wpixel = wall_pixel(vec_dis(inter.pos, pos));
	y_start = (W_Y - wpixel) / 2;
	y_end = ((W_Y + wpixel) / 2) - 1;
	j = 0;
	while (j < W_Y)
	{
		if (j < y_start)
		{
			//draw sky
			my_mlx_pixel_put(data, index, j, create_rgb(0x99, 0xCC, 0xFF));
		}
		else if (y_end < j)
		{
			//draw floor
			my_mlx_pixel_put(data, index, j, create_rgb(0xDC, 0xDC, 0xDC));
		}
		else
		{
			//draw wall
			my_mlx_pixel_put(data, index, j, create_rgb(0x80, 0x80, 0x80));
		}
		j++;
	}
}