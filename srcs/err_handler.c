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
	if (!game->hei || !game->wid)
		print_err("Uninitialized data exists\n", game);
	if (!game->n_texure || !game->s_texure
		|| !game->e_texure || !game->w_texure)
		print_err("Uninitialized data exists\n", game);
	//RGB color 범위 제한 [0, 255]
	if (!game->c_color || !game->f_color)
		print_err("invalid color information exist\n", game);
	if (game->f_color->red > 255 || game->f_color->red < 0
		|| game->f_color->green > 255 || game->f_color->green < 0
		|| game->f_color->blue > 255 || game->f_color->blue < 0)
		print_err("color code range error\n", game);
}

void	exit_game(t_game *game)
{
	// free(game->str_map);
	// game->str_map = NULL;
	free(game);
	game = NULL;
	exit(0);
}
