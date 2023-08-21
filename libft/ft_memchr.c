/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:35:56 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 11:43:27 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*arr;

	i = 0;
	arr = (const unsigned char *)s;
	while (i < n)
	{
		if (arr[i] == (unsigned char)c)
			return ((void *)(arr + i));
		i++;
	}
	return (NULL);
}
