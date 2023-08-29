/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:01:52 by bojung            #+#    #+#             */
/*   Updated: 2023/08/02 14:01:54 by bojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	init_game(t_game *game)
{
	game->hei = 0;
	game->wid = 0;
	game->n_texture = 0;
	game->s_texture = 0;
	game->e_texture = 0;
	game->w_texture = 0;
	game->cd_texture = 0;
	game->map = 0;
	game->direction = 0;
	ft_memset(&game->flags, 0, sizeof(t_flags));
	ft_memset(&game->f_color, 0, sizeof(t_color));
	ft_memset(&game->c_color, 0, sizeof(t_color));
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*get_valid_line(int fd)
{
	char	*ret_str;
	char	*line;
	char	*temp_line;
	int		len;
	int		i;

	i = -1;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	temp_line = line;
	len = ft_strlen(line);
	while (is_whitespace(line[++i]))
		line[i] = ' ';
	while (len - 1 >= 0 && (is_whitespace(line[len - 1])
			|| line[len - 1] == '\n'))
		len--;
	if (len == 0)
		len = 1;
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, line, len + 1);
	free(temp_line);
	return (ret_str);
}

char	*erase_space(char *line)
{
	int		i;
	char	*ret_str;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	ret_str = ft_strdup(line + i);
	return (ret_str);
}

void	is_valid_code(char *line)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		print_err("Invalid color code1\n");
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] != ',' && line[i] != '\0')
		print_err("Invalid color cod2\n");
	i++;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == ',')
		print_err("Invalid color code3\n");
}
