/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:58:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 16:16:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

static void	init_player_dir(t_vec2 *dir, char c_dir)
{
	if (c_dir == 'N')
	{
		dir->x = 0.0;
		dir->y = -1.0;
	}
	else if (c_dir == 'S')
	{
		dir->x = 0.0;
		dir->y = 1.0;
	}
	else if (c_dir == 'E')
	{
		dir->x = 1.0;
		dir->y = 0.0;
	}
	else if (c_dir == 'W')
	{
		dir->x = -1.0;
		dir->y = 0.0;
	}
}

void	init_player(t_player *player, char **map, size_t dx, size_t dy)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dy)
	{
		j = 0;
		while (j < dx)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' \
			|| map[i][j] == 'W')
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				init_player_dir(&(player->dir), map[i][j]);
			}
			j++;
		}
		i++;
	}
}
