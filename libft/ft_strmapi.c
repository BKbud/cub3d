/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:47:44 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 14:24:32 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	if (!f)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
