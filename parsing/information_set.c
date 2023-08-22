/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:27:19 by bojung            #+#    #+#             */
/*   Updated: 2023/08/02 17:27:20 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * function:	texture, color 등의 Type을 확인하고 관련 구조체에 저장합니다.
 * return:		map의 시작 문자열
 */
char	*type_identifier(t_game *game, int fd)
{
	char	*line;
	char	*temp_line;

	line = get_valid_line(fd);
	while (TRUE)
	{
		if (!line)
			return (NULL);
		temp_line = line;
		while (is_space(*line))
			line++;
		if (set_data(game, line) || *line == '\n')
			line = get_valid_line(fd);
		else if (*line == '1')
			return (temp_line);
		else
			print_err("Invalid information\n");
		free(temp_line);
	}
	return (NULL);
}

/*
 * function:	색 정보를 int형으로 반환하여 구조체에 저장합니다.
 * return:		color 구조체 포인터
 */
t_color	*set_color(char *line)
{
	t_color	*color;
	int		len;
	int		comma_num;

	len = 0;
	comma_num = 0;
	while (line[len])
	{
		if (line[len] != ',' && !is_space(line[len]) && (line[len] < '0' || line[len] > '9'))
			return (NULL);
		if (line[len++] == ',')
			comma_num++;
	}
	color = malloc(sizeof(t_color *));
	if (!color || comma_num != 2 || line[len - 1] == ',')
		return (NULL);
	color->red = ft_atoi(line);
	while (*line != ',' && *(line + 1))
		line++;
	color->green = ft_atoi(++line);
	while (*line != ',' && *(line + 1))
		line++;
	color->blue = ft_atoi(++line);
	while (*line)
		if (is_space(*(line++)))
			print_err("Invalid color information exists\n");
	return (color);
}
/*
 * function:	타입에 맞는 데이터를 초기화합니다.
 * return:		TRUE/FALSE
 */
int	set_data(t_game *game, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		game->n_texture = erase_space(line + 3);
	else if (!ft_strncmp("SO ", line, 3))
		game->s_texture = erase_space(line + 3);
	else if (!ft_strncmp("WE ", line, 3))
		game->w_texture = erase_space(line + 3);
	else if (!ft_strncmp("EA ", line, 3))
		game->e_texture = erase_space(line + 3);
	else if (!ft_strncmp("F ", line, 2))
		game->f_color = set_color(line + 2);
	else if (!ft_strncmp("C ", line, 2))
		game->c_color = set_color(line + 2);
	else
		return (0);
	game->d_flag++;
	return (1);
}
