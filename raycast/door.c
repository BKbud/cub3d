/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:31:30 by bojung            #+#    #+#             */
/*   Updated: 2023/08/26 15:31:35 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_data *data)
{
	char	**map;

	map = data->game->map;
	if (map[(int)(data->player.pos.y)][(int)data->player.pos.x - 1] == '2')
		map[(int)(data->player.pos.y)][(int)data->player.pos.x - 1] = '3';
	else if (map[(int)(data->player.pos.y - 1)][(int)data->player.pos.x] == '2')
		map[(int)(data->player.pos.y - 1)][(int)data->player.pos.x] = '3';
	else if (map[(int)(data->player.pos.y + 1)][(int)data->player.pos.x] == '2')
		map[(int)(data->player.pos.y + 1)][(int)data->player.pos.x] = '3';
	else if (map[(int)(data->player.pos.y)][(int)data->player.pos.x + 1] == '2')
		map[(int)(data->player.pos.y)][(int)data->player.pos.x + 1] = '3';
	else
		close_door(data);
}

void	close_door(t_data *data)
{
	char	**map;

	map = data->game->map;
	if (map[(int)(data->player.pos.y)][(int)data->player.pos.x - 1] == '3')
		map[(int)(data->player.pos.y)][(int)data->player.pos.x - 1] = '2';
	else if (map[(int)(data->player.pos.y - 1)][(int)data->player.pos.x] == '3')
		map[(int)(data->player.pos.y - 1)][(int)data->player.pos.x] = '2';
	else if (map[(int)(data->player.pos.y + 1)][(int)data->player.pos.x] == '3')
		map[(int)(data->player.pos.y + 1)][(int)data->player.pos.x] = '2';
	else if (map[(int)(data->player.pos.y)][(int)data->player.pos.x + 1] == '3')
		map[(int)(data->player.pos.y)][(int)data->player.pos.x + 1] = '2';
}
