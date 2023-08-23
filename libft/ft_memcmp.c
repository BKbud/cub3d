/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:53:33 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 10:41:28 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*arr1;
	const unsigned char	*arr2;
	size_t				i;

	i = 0;
	arr1 = (const unsigned char *)s1;
	arr2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}
