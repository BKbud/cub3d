/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:32:35 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 16:18:06 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_move(t_player *player, int keycode)
{
	if (keycode == KEY_W)
		player->pos = vec_plus(player->pos, vec_mul(player->dir, D_MOV));
	else if (keycode == KEY_A)
	{
		player->pos = vec_plus(player->pos, \
		vec_mul(vec_rot(player->dir, -M_PI_2), D_MOV));
	}
	else if (keycode == KEY_S)
	{
		player->pos = vec_plus(player->pos, \
		vec_mul(vec_rot(player->dir, M_PI), D_MOV));
	}
	else if (keycode == KEY_D)
	{
		player->pos = vec_plus(player->pos, \
		vec_mul(vec_rot(player->dir, M_PI_2), D_MOV));
	}
}

void	player_rotate(t_player *player, int keycode)
{
	if (keycode == KEY_LEFT)
		player->dir = vec_rot(player->dir, -D_ROT);
	else if (keycode == KEY_RIGHT)
		player->dir = vec_rot(player->dir, D_ROT);
}

void	player_key(t_player *player, int keycode, int key)
{
	if (keycode == KEY_W)
		player->key.key_w = key;
	else if (keycode == KEY_A)
		player->key.key_a = key;
	else if (keycode == KEY_S)
		player->key.key_s = key;
	else if (keycode == KEY_D)
		player->key.key_d = key;
	else if (keycode == KEY_LEFT)
		player->key.key_left = key;
	else if (keycode == KEY_RIGHT)
		player->key.key_right = key;
}

int	if_collision(t_vec2 pos, char **map, size_t wid, size_t hei)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	x1 = pos.x - COL;
	x2 = pos.x + COL;
	y1 = pos.y - COL;
	y2 = pos.y + COL;
	if (0 <= x1 && x1 < wid && 0 <= x2 && x2 < wid && 0 <= y1 \
	&& y1 < hei && 0 <= y2 && y2 < hei)
	{
		if (map[(int)y1][(int)x1] != '1' && map[(int)y1][(int)x1] != ' ' && map[(int)y1][(int)x1] != '2'\
		&& map[(int)y1][(int)x2] != '1' && map[(int)y1][(int)x2] != ' '  && map[(int)y1][(int)x2] != '2'\
		&& map[(int)y2][(int)x1] != '1' && map[(int)y2][(int)x1] != ' ' && map[(int)y2][(int)x1] != '2'\
		&& map[(int)y2][(int)x2] != '1' && map[(int)y2][(int)x2] != ' ' && map[(int)y2][(int)x2] != '2')
			return (0);
	}
	return (1);
}

void	player_set(t_player *player, char **map, size_t wid, size_t hei)
{
	t_vec2	pos_init;

	pos_init = player->pos;
	if (player->key.key_w)
		player_move(player, KEY_W);
	if (player->key.key_a)
		player_move(player, KEY_A);
	if (player->key.key_s)
		player_move(player, KEY_S);
	if (player->key.key_d)
		player_move(player, KEY_D);
	if (player->key.key_left)
		player_rotate(player, KEY_LEFT);
	if (player->key.key_right)
		player_rotate(player, KEY_RIGHT);
	if (if_collision(player->pos, map, wid, hei))
		player->pos = pos_init;
}
