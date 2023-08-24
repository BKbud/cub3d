/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_single_step_y.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:41:59 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 15:32:27 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	raycast_single_step_d(t_vec2 pos, t_vec2 dir, t_game *game, \
t_cpoint *inter)
{
	double	t;
	int		y;

	y = (int)pos.y;
	while (1)
	{
		y++;
		t = (y - pos.y) / dir.y;
		inter->pos.x = pos.x + t * dir.x;
		if (0 <= inter->pos.x && inter->pos.x < game->wid && 0 <= y && y < (int)game->hei)
		{
			if (game->map[y][(int)inter->pos.x] == '1')
			{
				inter->pos.y = y;
				inter->c_dir = 'N';
				break ;
			}
		}
		else
			break ;
	}
}

static void	raycast_single_step_u(t_vec2 pos, t_vec2 dir, t_game *game, \
t_cpoint *inter)
{
	double	t;
	int		y;

	y = (int)pos.y;
	while (1)
	{
		t = (y - pos.y) / dir.y;
		inter->pos.x = pos.x + t * dir.x;
		if (0 <= inter->pos.x && inter->pos.x < game->wid && 0 <= y - 1 && y - 1 < (int)game->hei)
		{
			if (game->map[y - 1][(int)inter->pos.x] == '1')
			{
				inter->pos.y = y;
				inter->c_dir = 'S';
				break ;
			}
		}
		else
			break ;
		y--;
	}
}

t_cpoint	raycast_single_step_y(t_vec2 pos, t_vec2 dir, t_game *game)
{
	t_cpoint	inter;

	ft_memset(&inter, 0, sizeof(t_cpoint));
	if (dir.y > 0)
		raycast_single_step_d(pos, dir, game, &inter);
	else
		raycast_single_step_u(pos, dir, game, &inter);
	return (inter);
}
