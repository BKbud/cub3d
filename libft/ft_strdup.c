/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:24:46 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 19:15:21 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;

	len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, len + 1);
	return (arr);
}
