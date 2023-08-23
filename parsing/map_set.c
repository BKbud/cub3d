/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:58:08 by bojung            #+#    #+#             */
/*   Updated: 2022/09/29 10:58:09 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open failed\n");
	line = type_identifier(game, fd);
	check_max_wid(game, line, fd);
	init_map(game, fd, filename);
	check_init_data(game);
}

void	check_max_wid(t_game *game, char *line, int fd)
{
	int	i;

	while (TRUE)
	{
		i = 0;
		if (!line)
		{
			close(fd);
			break ;
		}
		while (is_whitespace(line[i]))
			i++;
		game->hei++;
		if (game->wid < ft_strlen(line))
			game->wid = ft_strlen(line);
		free(line);
		line = get_valid_line(fd);
	}
}

void	init_map(t_game *game, int fd, char *filename)
{
	size_t	i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open failed\n");
	game->map = (char **)malloc(sizeof(char *) * (game->hei + 1));
	if (!game->map)
		print_err("File open failed\n");
	line = jump_to_map(fd);
	while (i < game->hei)
	{
		if (!line)
			print_err("Map error\n");
		game->map[i] = malloc(sizeof(char) * (game->wid + 1));
		if (!game->map[i])
			print_err("File open failed\n");
		space_adder(game, game->map[i], line);
		free (line);
		line = get_valid_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

char	*jump_to_map(int fd)
{
	char	*line;
	char	*temp_line;

	while (TRUE)
	{
		line = get_valid_line(fd);
		if (!line)
			print_err("There is no map\n");
		temp_line = line;
		while (is_whitespace(*line))
			line++;
		if (*line == '1' || *line == '0')
			break ;
		free(temp_line);
	}
	return (temp_line);
}
