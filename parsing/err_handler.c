/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:57:05 by bojung            #+#    #+#             */
/*   Updated: 2023/08/23 16:57:44 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	print_err(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(1);
}

void	check_extension(char *filename)
{
	int	idx;

	idx = 1;
	while (*(filename + idx) != '.')
		idx++;
	if (ft_strncmp(filename + idx, ".cub", 5) != 0)
		print_err("File extension error\n");
}

void	check_init_data(t_game *game)
{
	if (game->hei <= 0 || game->wid <= 0)
		print_err("Uninitialized data exists\n");
	if (!game->n_texture || !game->s_texture
		|| !game->e_texture || !game->w_texture)
		print_err("Uninitialized data exists\n");
	if (!game->c_color || !game->f_color)
		print_err("Invalid color information exist\n");
	printf("%d\n", game->f_color->blue);
	if (game->f_color->red > 255 || game->f_color->red < 0
		|| game->f_color->green > 255 || game->f_color->green < 0
		|| game->f_color->blue > 255 || game->f_color->blue < 0
		|| game->c_color->red > 255 || game->c_color->red < 0
		|| game->c_color->green > 255 || game->c_color->green < 0
		|| game->c_color->blue > 255 || game->c_color->blue < 0)
		print_err("Color code range error\n");
	map_check(game);
	if (game->flags.d_flag != 1)
		print_err("More or less Character exists\n");
	if (game->flags.door_flag && !game->cd_texture)
		print_err("Uninitialized data exists\n");
}

void	map_check(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != ' ' && game->map[i][j] != '2'
				&& game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'N' && game->map[i][j] != 'S'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'W')
				print_err("There is invalid character in the map\n");
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->direction = game->map[i][j];
				game->flags.d_flag++;
			}
			if (game->map[i][j] == '2')
				game->flags.door_flag = 1;
		}
	}
	validation_check(game);
}

void	validation_check(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '2'
				|| game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				if (i == 0 || i == game->hei - 1
					|| j == 0 || j == game->wid - 1)
					print_err("Invalid map\n");
				else if (game->map[i][j - 1] == ' '
					|| game->map[i][j + 1] == ' ')
					print_err("Invalid map\n");
				else if (game->map[i - 1][j] == ' '
					|| game->map[i + 1][j] == ' ')
					print_err("Invalid map\n");
			}
		}
	}
}
