/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:44:05 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 18:45:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	sum;
	int		i;

	a = ft_strlen(dest);
	b = ft_strlen(src);
	i = 0;
	sum = a + b;
	if (size == 0)
		return (b + size);
	while (a < size - 1 && src[i])
	{
		dest[a++] = src[i++];
	}
	dest[a] = '\0';
	if (size < a)
		return (b + size);
	else
		return (sum);
}
