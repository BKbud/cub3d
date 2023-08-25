/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:24:09 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/25 15:23:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	minimap(t_player *player, t_game *game, t_data *data)
{
	int	mx;
	int	my;
	int	i;
	int	j;
	t_vec2	temp;

	mx = (int) (W_X / 5);
	my = (int) (W_Y / 5);
	j = 0;
	while (j < my)
	{
		i = 0;
		while (i < mx)
		{
			if (i == 0 || i == mx - 1 || j == 0 || j == my - 1)
				my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0x000000);
			else if (0.48 * mx <= i && i < 0.52 * mx && 0.48 * my <= j && j < 0.52 * my)
				my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0xFF0000);
			else
			{
				temp.x = player->pos.x + ((double)MAP_SCALE / mx) * (i - (double)mx / 2);
				temp.y = player->pos.y + ((double)MAP_SCALE / mx) * (j - (double)my / 2);
				if (0 <= temp.x && temp.x < game->wid && 0 <= temp.y && temp.y < game->hei)
				{
					if (game->map[(int)temp.y][(int)temp.x] == '1')
						my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0x808080);
					else if (game->map[(int)temp.y][(int)temp.x] == ' ')
						my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0xf9f9f9);
					else
						my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0xdcdcdc);
				}
				else
					my_mlx_pixel_put(data, (int)(i + W_X * 0.75), (int)(j + W_Y * 0.05), 0xf9f9f9);
			}
			i++;
		}
		j++;
	}
}
