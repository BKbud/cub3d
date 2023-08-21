/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:35:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/21 19:16:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define D_X 6
#define D_Y 5

void	init_player_dir(double *dirX, double *dirY, char dir)
{
	if (dir == 'N')
	{
		*dirX = 0.0;
		*dirY = -1.0;
	}
	else if (dir == 'S')
	{
		*dirX = 0.0;
		*dirY = 1.0;
	}
	else if (dir == 'E')
	{
		*dirX = 1.0;
		*dirY = 0.0;
	}
	else if (dir == 'W')
	{
		*dirX = -1.0;
		*dirY = 0.0;
	}
}

void	init_player(t_player *player, const char **map)
{
	int			i;
	int			j;

	i = 0;
	while (i < D_Y)
	{
		j = 0;
		while (j < D_X)
		{
			if (map[i][j] != '0' && map[i][j] != '1')
			{
				player->posX = j + 0.5;
				player->posY = i + 0.5;
				init_player_dir(player->dirX, player->dirY, map[i][j]);
			}
			j++;
		}
		i++;
	}
}

int	step_sign(double val)
{
	if (val > 0)
		return (1);
	else if (val < 0)
		return (-1);
	else
		return (0);
}

int	main()
{
	char	map[D_Y][D_X] = {
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '1'},
		{'1', '1', '0', '0', 'N', '1'},
		{'1', '1', '1', '1', '1', '1'} 
	};
	t_player	player;

	init_player(&player, map);
}

int	main()
{
	char	map[D_Y][D_X] = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1} 
	};
	double	posX = 4.5;
	double	posY = 3.1;
	double	rad = M_PI + M_PI/4;
	double	dirX = cos(rad);
	double	dirY = sin(rad);
	int		xstep = 0;
	int		ystep = 0;

	xstep = step_sign(dirX);
	ystep = step_sign(dirY);

	double	t;
	double	interX;
	double	interY;
	if (xstep)
	{
		int	x = (int) posX;
		if (xstep > 0)
		{
			while (1)
			{
				x++;
				t = (x - posX) / dirX;
				interY = posY + t * dirY;
				if (0 <= interY && interY <= D_Y)
				{
					if (map[(int)interY][x])
						break;
				}
				else
				{
					x = -1;
					break ;
				}
			}
		}
		else
		{
			while (1)
			{
				t = (x - posX) / dirX;
				interY = posY + t * dirY;
				if (0 <= interY && interY <= D_Y)
				{
					if (map[(int)interY][x - 1])
						break;
				}
				else
				{
					x = -1;
					break ;
				}
				x--;
			}
		}
		if (x >= 0)
			printf("inter x : (%d,%lf)\n", x, interY);
	}
	if (ystep)
	{
		int	y = (int) posY;
		if (ystep > 0)
		{
			while (1)
			{
				y++;
				t = (y - posY) / dirY;
				interX = posX + t * dirX;
				if (0 <= interX && interX <= D_X)
				{
					if (map[y][(int)interX])
						break;
				}
				else
				{
					y = -1;
					break ;
				}
			}
		}
		else
		{
			while (1)
			{
				t = (y - posY) / dirY;
				interX = posX + t * dirX;
				if (0 <= interX && interX <= D_X)
				{
					if (map[y - 1][(int)interX])
						break;
				}
				else
				{
					y = -1;
					break ;
				}
				y--;
			}
		}
		if (y >= 0)
			printf("inter y : (%lf,%d)\n", interX, y);
	}
	return (0);
}
