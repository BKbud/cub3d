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

#include "../includes/cub3d.h"

/*
 * function:	공백 문자 여부를 확인
 * return:		True/False
 * 
 * 개행은 확인하지 않습니다.
 */
int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

// 파일을 한 줄 읽은 후 뒤 공백을 제거한 문자열을 반환합니다. 앞의 공백은 따로 처리하지 않습니다.
char	*get_valid_line(int fd)
{
	char	*ret_str;
	char	*line;
	char	*temp_line;
	int		len;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	temp_line = line;
	len = ft_strlen(line);
	while (is_space(line[i]))
	{
		line[i] = ' ';
		i++;
	}
	while (len - 1 >= 0 && (is_space(line[len - 1]) || line[len - 1] == '\n'))
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

// 단순히 문자열 앞의 공백만을 제거한 후 반환합니다. 따로 기존 문자열에 대해 할당 해제는 하지 않습니다.
char	*erase_space(char *line)
{
	int		i;
	char	*ret_str;

	i = 0;
	while (is_space(line[i]))
		i++;
	ret_str = ft_strdup(line + i);
	return (ret_str);
}

/*
 * function:	문자열의 여백에 맵의 최대 너비까지 공백을 추가합니다.
 * return:		None
 */
void	space_adder(t_game *game, char *map, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	ft_strlcpy(map, line, len + 1);
	if (len != game->wid)
	{
		if (*map == '\n')
			len--;
		while (len < game->wid)
		{
			map[len] = ' ';
			len++;
		}
	}
	map[game->wid] = '\0';
}

void	init_game(t_game *game)
{
	game->hei = 0;
	game->wid = 0;
	game->n_texure = 0;
	game->s_texure = 0;
	game->e_texure = 0;
	game->w_texure = 0;
	game->f_color = 0;
	game->c_color = 0;
	game->map = 0;
}
