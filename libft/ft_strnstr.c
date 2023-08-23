/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:05:31 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 14:51:46 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(str);
	n2 = ft_strlen(to_find);
	i = 0;
	while (i + n2 <= len && i + n2 <= n1)
	{
		j = 0;
		while (j < n2)
		{
			if (to_find[j] != str[i + j])
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
