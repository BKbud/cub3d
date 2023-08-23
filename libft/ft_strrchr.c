/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:26:26 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 18:53:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*arr;

	arr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			arr = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (arr);
}
