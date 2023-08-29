/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:27:19 by bojung            #+#    #+#             */
/*   Updated: 2023/08/23 16:57:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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
		while (is_whitespace(*line))
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

t_color	*set_color(char *line)
{
	t_color	*color;

	check_color(line);
	color = malloc(sizeof(t_color *));
	if (!color)
		return (NULL);
	is_valid_code(line);
	color->red = ft_atoi(line);
	while (*line != ',' && *(line + 1))
		line++;
	is_valid_code(++line);
	color->green = ft_atoi(line);
	while (*line != ',' && *(line + 1))
		line++;
	is_valid_code(++line);
	color->blue = ft_atoi(line);
	return (color);
}

void	check_color(char *line)
{
	int	len;
	int	comma_num;

	len = 0;
	comma_num = 0;
	if (line[0] == ',')
		print_err("Invalid color code\n");
	while (line[len])
	{
		if (line[len] != ',' && !is_whitespace(line[len])
			&& (line[len] < '0' || line[len] > '9'))
			print_err("Invalid Color code\n");
		if (line[len++] == ',')
			comma_num++;
	}
	if (comma_num != 2)
		print_err("Invalid Color code\n");
}

int	set_data(t_game *game, char *line)
{
	set_flags(game, line);
	if (!ft_strncmp("NO ", line, 3))
		game->n_texture = erase_space(line + 3);
	else if (!ft_strncmp("SO ", line, 3))
		game->s_texture = erase_space(line + 3);
	else if (!ft_strncmp("WE ", line, 3))
		game->w_texture = erase_space(line + 3);
	else if (!ft_strncmp("EA ", line, 3))
		game->e_texture = erase_space(line + 3);
	else if (!ft_strncmp("CD ", line, 3))
		game->cd_texture = erase_space(line + 3);
	else if (!ft_strncmp("F ", line, 2))
		game->f_color = set_color(line + 2);
	else if (!ft_strncmp("C ", line, 2))
		game->c_color = set_color(line + 2);
	else
		return (0);
	return (1);
}

void	set_flags(t_game *game, char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		game->flags.n_flag++;
	else if (!ft_strncmp("SO ", line, 3))
		game->flags.s_flag++;
	else if (!ft_strncmp("WE ", line, 3))
		game->flags.w_flag++;
	else if (!ft_strncmp("EA ", line, 3))
		game->flags.e_flag++;
	else if (!ft_strncmp("CD ", line, 3))
		game->flags.door_flag++;
	else if (!ft_strncmp("F ", line, 2))
		game->flags.f_flag++;
	else if (!ft_strncmp("C ", line, 2))
		game->flags.c_flag++;
	if (game->flags.n_flag > 1 || game->flags.s_flag > 1
		|| game->flags.w_flag > 1 || game->flags.e_flag > 1
		|| game->flags.f_flag > 1 || game->flags.c_flag > 1
		|| game->flags.door_flag > 1)
		print_err("More informations exist\n");
}
