/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:02:59 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 20:35:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	arrlen(const char *s1, const char *set, int num)
{
	int	i;
	int	len;
	int	sum;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	sum = 0;
	while (s1[i])
	{
		if (!is_set(s1[i], set))
		{
			sum++;
			if (!flag)
				flag = 1;
		}
		if (flag)
			len++;
		if (sum >= num)
			flag = 0;
		i++;
	}
	return (len);
}

void	arrcpy(char *arr, const char *s1, const char *set, int num)
{
	int	i;
	int	len;
	int	sum;
	int	flag;

	i = -1;
	len = 0;
	flag = 0;
	sum = 0;
	while (s1[++i])
	{
		if (!is_set(s1[i], set))
		{
			sum++;
			if (!flag)
				flag = 1;
		}
		if (flag)
		{
			arr[len++] = s1[i];
		}
		if (sum >= num)
			flag = 0;
	}
	arr[len] = '\0';
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		num;
	int		i;
	int		len;
	char	*arr;

	num = 0;
	i = 0;
	while (s1[i])
	{
		if (!is_set(s1[i], set))
			num++;
		i++;
	}
	len = arrlen(s1, set, num);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arrcpy(arr, s1, set, num);
	return (arr);
}
