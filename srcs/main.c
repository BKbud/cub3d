/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:04:57 by bojung            #+#    #+#             */
/*   Updated: 2023/08/18 19:04:59 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		print_err("Map file missing\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_err("Allocation failed\n");
	check_extension(av[1]);
	init_game(game);
	read_map(av[1], game);
	return (0);
}
