/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:54:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:17:10 by hanryu           ###   ########.fr       */
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
# define D_ROT 0.05
# define D_MOV 0.05

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
}	t_player;

void	init_player(t_player *player, char **map, size_t dx, size_t dy);
void	player_move(t_player *player, int keycode);
void	player_rotate(t_player *player, int keycode);

#endif