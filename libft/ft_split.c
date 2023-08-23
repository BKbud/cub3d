/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:51:21 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/07 12:44:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	arr_height(const char *s, char c)
{
	int	i;
	int	flag;
	int	n;

	i = 0;
	flag = 0;
	n = 0;
	while (s[i])
	{
		if (!flag && s[i] != c)
		{
			flag = 1;
			n++;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (n);
}

static void	into_arr(const char *pt, char c, int num, char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (pt[len] && pt[len] != c)
	{
		len++;
	}
	arr[num] = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr[num])
		return ;
	while (i < len)
	{
		arr[num][i] = pt[i];
		i++;
	}
	arr[num][i] = '\0';
}

static void	free_arr(char **arr, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(arr[i]);
		i++;
	}
}

static int	arr_split(const char *s, char c, char **arr)
{
	int	i;
	int	str_num;
	int	flag;

	i = 0;
	str_num = 0;
	flag = 0;
	while (s[i])
	{
		if (!flag && s[i] != c)
		{
			into_arr(&s[i], c, str_num, arr);
			if (!arr[str_num])
			{
				free_arr(arr, str_num);
				return (0);
			}
			str_num++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		height;
	char	**arr;

	height = arr_height(s, c);
	arr = (char **)malloc(sizeof(char *) * (height + 1));
	if (!arr)
		return (NULL);
	arr[height] = 0;
	if (!arr_split(s, c, arr))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
