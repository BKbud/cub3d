/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:35:25 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 15:47:35 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_key(&data->player, keycode, 1);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_key(&data->player, keycode, 0);
	return (0);
}

int	key_exit(t_data *data)
{
	(void)data;
	exit (0);
}

int	main_loop(t_data *data)
{
	data->img = mlx_new_image(data->mlx, W_X, W_Y);
	if (!data->img)
		exit (1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	// raycast
	player_set(&data->player, data->game->map, data->game->wid, data->game->hei);
	raycast(&data->player, data->game, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		*game;
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
	init_player(&data.player, game->map, game->wid, game->hei);
	data.game = game;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_X, W_Y, "cub3d");
	mlx_hook(data.win, EVENT_KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, EVENT_KEY_RELEASE, 0, key_release, &data);
	mlx_hook(data.win, EVENT_KEY_EXIT, 0, key_exit, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
