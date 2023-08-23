/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:35:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/22 15:58:06 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"
#include "./includes/cub3d.h"

void	init_player_dir(t_vec2 *dir, char c_dir)
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

void	init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < D_Y)
	{
		j = 0;
		while (j < D_X)
		{
			if (map[i][j] != '0' && map[i][j] != '1')
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

	init_player(&player, game->map);
	raycast(&player, (const char**)game->map, &data);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
