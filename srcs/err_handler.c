/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:57:05 by bojung            #+#    #+#             */
/*   Updated: 2023/07/26 14:57:07 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// 파일의 확장자를 확인합니다.
void	check_extension(char *filename)
{
	int	idx;

	idx = 1;
	while (*(filename + idx) != '.')
		idx++;
	if (ft_strncmp(filename + idx, ".cub", 5) != 0)
	{
		printf("File extension error\n");
		exit(0);
	}
}

void	print_err(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit_game(game);
}

// 추가 필요
void	check_init_data(t_game *game)
{
	if (game->hei <= 0 || game->wid <= 0)
		print_err("Uninitialized data exists1\n", game);
	if (!game->n_texure || !game->s_texure
		|| !game->e_texure || !game->w_texure)
		print_err("Uninitialized data exists2\n", game);
	if (!game->c_color || !game->f_color)
		print_err("invalid color information exist\n", game);
	if (game->f_color->red > 255 || game->f_color->red < 0
		|| game->f_color->green > 255 || game->f_color->green < 0
		|| game->f_color->blue > 255 || game->f_color->blue < 0)
		print_err("color code range error\n", game);
	map_check(game);
}

/*
 * function:	맵에 문자들을 하나씩 확인합니다. 또한 캐릭터의 방향을 저장합니다.
 * return:		None
 */
void	map_check(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != ' ' && game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'N' && game->map[i][j] != 'S'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'W')
				print_err("There is invalid character in the map\n", game);
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->direction = game->map[i][j];
				game->d_flag++;
			}
			j++;
		}
		i++;
	}
	if (game->d_flag != 1)
		print_err("There must be only one character\n", game);
}

void	exit_game(t_game *game)
{
	// free(game->str_map);
	// game->str_map = NULL;
	free(game);
	game = NULL;
	exit(0);
}
