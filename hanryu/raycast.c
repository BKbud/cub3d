/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:10:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/22 15:46:05 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	rotate_ray_h(t_vec2 p_dir, int i)
{
	double	theta;

	theta = (FOV_H / (W_X - 1)) * (i - ((double)(W_X + 1) / 2));
	return (vec_rot(p_dir, theta));
}

t_cpoint	raycast_single_step_x(t_vec2 pos, t_vec2 dir, const char **map)
{
	t_cpoint	inter;
	double		t;
	int			x;

	ft_memset(&inter, 0, sizeof(t_cpoint));
	x = (int) pos.x;
	if (dir.x > 0)
	{
		while (1)
		{
			x++;
			t = (x - pos.x) / dir.x;
			inter.pos.y = pos.y + t * dir.y;
			if (0 <= inter.pos.y && inter.pos.y < D_Y)
			{
				if (map[(int)inter.pos.y][x] == '1')
				{
					inter.pos.x = x;
					inter.c_dir = 'W';
					break ;
				}
			}
			else
				break ;
		}
	}
	else
	{
		while (1)
		{
			t = (x - pos.x) / dir.x;
			inter.pos.y = pos.y + t * dir.y;
			if (0 <= inter.pos.y && inter.pos.y < D_Y)
			{
				if (map[(int)inter.pos.y][x - 1] == '1')
				{
					inter.pos.x = x;
					inter.c_dir = 'E';
					break ;
				}
			}
			else
				break ;
			x--;
		}
	}
	return (inter);
}

t_cpoint	raycast_single_step_y(t_vec2 pos, t_vec2 dir, const char **map)
{
	t_cpoint	inter;
	double		t;
	int			y;

	ft_memset(&inter, 0, sizeof(t_cpoint));
	y = (int) pos.y;
	if (dir.y > 0)
	{
		while (1)
		{
			y++;
			t = (y - pos.y) / dir.y;
			inter.pos.x = pos.x + t * dir.x;
			if (0 <= inter.pos.x && inter.pos.x < D_X)
			{
				if (map[y][(int)inter.pos.x] == '1')
				{
					inter.pos.y = y;
					inter.c_dir = 'N';
					break ;
				}
			}
			else
				break ;
		}
	}
	else
	{
		while (1)
		{
			t = (y - pos.y) / dir.y;
			inter.pos.x = pos.x + t * dir.x;
			if (0 <= inter.pos.x && inter.pos.x < D_X)
			{
				if (map[y - 1][(int)inter.pos.x] == '1')
				{
					inter.pos.y = y;
					inter.c_dir = 'S';
					break ;
				}
			}
			else
				break ;
			y--;
		}
	}
	return (inter);
}

t_cpoint	raycast_single_close(t_vec2 pos, t_cpoint inter_x, t_cpoint inter_y)
{
	if (vec_dis(inter_x.pos, pos) < vec_dis(inter_y.pos, pos))
		return (inter_x);
	return (inter_y);
}

t_cpoint	raycast_single(t_vec2 pos, t_vec2 dir, const char **map)
{
	t_cpoint	inter_x;
	t_cpoint	inter_y;

	ft_memset(&inter_x, 0, sizeof(t_cpoint));
	ft_memset(&inter_y, 0, sizeof(t_cpoint));
	if (!is_zero(dir.x))
		inter_x = raycast_single_step_x(pos, dir, map);
	if (!is_zero(dir.y))
		inter_y = raycast_single_step_y(pos, dir, map);
	return (raycast_single_close(pos, inter_x, inter_y));
}

void	raycast(t_player *player, const char **map, t_data *data)
{
	int	i;

	i = 1;
	while (i <= W_X)
	{
		draw_wall(player->pos, raycast_single(player->pos, rotate_ray_h(player->dir, i), map), i - 1, data);
		i++;
	}
}
