/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:32:35 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:38:43 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <stdio.h>

void	player_move(t_player *player, int keycode)
{
	if (keycode == KEY_W)
		player->pos = vec_plus(player->pos, vec_mul(player->dir, D_MOV));
	else if (keycode == KEY_A)
		player->pos = vec_plus(player->pos, vec_mul(vec_rot(player->dir, -M_PI_2), D_MOV));
	else if (keycode == KEY_S)
		player->pos = vec_plus(player->pos, vec_mul(vec_rot(player->dir, M_PI), D_MOV));
	else if (keycode == KEY_D)
		player->pos = vec_plus(player->pos, vec_mul(vec_rot(player->dir, M_PI_2), D_MOV));
}

void	player_rotate(t_player *player, int keycode)
{
	if (keycode == KEY_LEFT)
		player->dir = vec_rot(player->dir, -D_ROT);
	else if (keycode == KEY_RIGHT)
		player->dir = vec_rot(player->dir, D_ROT);
}

void	player_key_on(t_player *player, int keycode)
{
	if (keycode == KEY_W)
		player->key.key_w = 1;
	else if (keycode == KEY_A)
		player->key.key_a = 1;
	else if (keycode == KEY_S)
		player->key.key_s = 1;
	else if (keycode == KEY_D)
		player->key.key_d = 1;
	else if (keycode == KEY_LEFT)
		player->key.key_left = 1;
	else if (keycode == KEY_RIGHT)
		player->key.key_right = 1;
}

void	player_key_off(t_player *player, int keycode)
{
	if (keycode == KEY_W)
		player->key.key_w = 0;
	else if (keycode == KEY_A)
		player->key.key_a = 0;
	else if (keycode == KEY_S)
		player->key.key_s = 0;
	else if (keycode == KEY_D)
		player->key.key_d = 0;
	else if (keycode == KEY_LEFT)
		player->key.key_left = 0;
	else if (keycode == KEY_RIGHT)
		player->key.key_right = 0;
}

void	player_set(t_player *player)
{
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
}
