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

#include "../includes/cub3d.h"

void	print_test(t_game *game)
{
	size_t	i;

	i = 0;
	printf("----------------------test-------------------\n");
	printf("north texure : %s\n", game->n_texure);
	printf("south texure : %s\n", game->s_texure);
	printf("west texure : %s\n", game->w_texure);
	printf("east texure : %s\n", game->e_texure);
	printf("f_color R,G,B : %d,%d,%d\n", game->f_color->red, game->f_color->green, game->f_color->blue);
	printf("c_color R,G,B : %d,%d,%d\n", game->c_color->red, game->c_color->green, game->c_color->blue);
	printf("Height : %zu, Max width : %zu\n", game->hei, game->wid);
	printf("\n");
	while (i < game->hei)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("---------------------------------------------\n");
}

/*
 * function:	파일을 읽어 맵의 정보를 확인합니다.
 * return:		None
 * 
 * map information 초기화
 * map 초기화
 * 에러 체크
 */
void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail\n", game);
	line = type_identifier(game, fd);
	check_max_wid(game, line, fd);
	init_map(game, fd, filename);
	check_init_data(game);
	print_test(game);
}

/*
 * function:	맵의 최대 너비를 확인 후 저장합니다.
 * return:		None
 */
void	check_max_wid(t_game *game, char *line, int fd)
{
	while (TRUE)
	{

		if (!line)
			break ;
		game->hei++;
		if (game->wid < ft_strlen(line))
			game->wid = ft_strlen(line);
		free(line);
		line = get_valid_line(fd);
	}
}

/*
 * function:	game 구조체의 map을 초기화합니다.
 * return:		None
 * 
 * map은 이차원 배열이며, 각 문자열은 맵의 최대 너비만큼 할당받습니다.
 * 최대 너비보다 짧은 문자열의 경우 나머지 부분은 공백으로 채웁니다.
 */
void	init_map(t_game *game, int fd, char *filename)
{
	size_t	i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail\n", game);
	game->map = (char **)malloc(sizeof(char *) * (game->hei + 1));
	if (!game->map)
		print_err("File open fail\n", game);
	line = jump_to_map(game, fd);
	while (i < game->hei)
	{
		if (!line)
			print_err("Map error\n", game);
		game->map[i] = malloc(sizeof(char) * (game->wid + 1));
		if (!game->map[i])
			print_err("File open fail\n", game);
		space_adder(game, game->map[i], line);
		free (line);
		line = get_valid_line(fd);
		i++;
	}
	game->map[i] = NULL; 
	close(fd);
}

/*
 * function:	맵이 있는 곳까지 파일을 넘깁니다.
 * return:		맵의 첫 번째 문자열
 */
char	*jump_to_map(t_game *game, int fd)
{
	char	*line;
	char	*temp_line;

	line = get_valid_line(fd);
	if (!line)
		print_err("File open fail\n", game);
	while (TRUE)
	{
		temp_line = line;
		while (is_space(*line))
			line++;
		if (*line == '1' || *line == '0')
			break ;
		if (!line)
			print_err("There is no map\n", game);
		free(temp_line);
		line = get_valid_line(fd);
	}
	return (temp_line);
}
