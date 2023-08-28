/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:54:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/28 14:30:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <math.h>
# include <unistd.h>
# include "vec.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define D_ROT 0.1
# define D_MOV 0.08
# define COL 0.1

typedef struct s_key
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_left;
	int	key_right;
}	t_key;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_key	key;
}	t_player;

void	init_player(t_player *player, char **map, size_t dx, size_t dy);
void	player_key(t_player *player, int keycode, int key);
void	player_set(t_player *player, char **map, size_t wid, size_t hei);

#endif