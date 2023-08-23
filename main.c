/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:35:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/23 18:30:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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

static void	init_player(t_player *player, char **map, size_t dx, size_t dy)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dy)
	{
		j = 0;
		while (j < dx)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
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

int	main(int ac, char **av)
{
	t_game		*game;
	t_player	player;
	t_data		data;

	//--------------map parsing----------------
	if (ac != 2)
		print_err("Map file missing\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_err("Allocation failed\n");
	check_extension(av[1]);
	init_game(game);
	read_map(av[1], game);

	//---------------operation-----------------
	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_X, W_Y, "cub3d");
	data.img = mlx_new_image(data.mlx, W_X, W_Y);
	if (!data.img)
		exit (1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);

	init_player(&player, game->map, game->wid, game->hei);
	raycast(&player, game, &data);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
