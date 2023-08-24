/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:32:35 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:15:36 by hanryu           ###   ########.fr       */
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
