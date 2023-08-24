/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_single_step_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:36:58 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 16:21:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	raycast_single_step_r(t_vec2 pos, t_vec2 dir, t_game *game, \
t_cpoint *inter)
{
	double	t;
	int		x;

	x = (int)pos.x;
	while (1)
	{
		x++;
		t = (x - pos.x) / dir.x;
		inter->pos.y = pos.y + t * dir.y;
		if (0 <= inter->pos.y && inter->pos.y < game->hei \
		&& 0 <= x && x < (int)game->wid)
		{
			if (game->map[(int)inter->pos.y][x] == '1')
			{
				inter->pos.x = x;
				inter->c_dir = 'W';
				break ;
			}
		}
		else
			break ;
	}
}

static void	raycast_single_step_l(t_vec2 pos, t_vec2 dir, t_game *game, \
t_cpoint *inter)
{
	double	t;
	int		x;

	x = (int)pos.x;
	while (1)
	{
		t = (x - pos.x) / dir.x;
		inter->pos.y = pos.y + t * dir.y;
		if (0 <= inter->pos.y && inter->pos.y < game->hei \
		&& 0 <= x - 1 && x - 1 < (int)game->wid)
		{
			if (game->map[(int)inter->pos.y][x - 1] == '1')
			{
				inter->pos.x = x;
				inter->c_dir = 'E';
				break ;
			}
		}
		else
			break ;
		x--;
	}
}

t_cpoint	raycast_single_step_x(t_vec2 pos, t_vec2 dir, t_game *game)
{
	t_cpoint	inter;

	ft_memset(&inter, 0, sizeof(t_cpoint));
	if (dir.x > 0)
		raycast_single_step_r(pos, dir, game, &inter);
	else
		raycast_single_step_l(pos, dir, game, &inter);
	return (inter);
}
