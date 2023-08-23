/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:43:10 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 20:01:35 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;
	char	*arr;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_1)
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}
