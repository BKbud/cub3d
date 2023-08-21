/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:19:58 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 11:47:56 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	str_len(int n)
{
	if (!n)
		return (0);
	return (1 + str_len(n / 10));
}

char	*ft_itoa(int n)
{
	int		buff;
	int		minus;
	char	*str;

	buff = 0;
	minus = 1;
	if (n <= 0)
		buff++;
	if (n < 0)
		minus = -1;
	buff += str_len(n);
	str = (char *)malloc(sizeof(char) * (buff + 1));
	if (!str)
		return (NULL);
	str[buff--] = '\0';
	if (minus < 0 && n)
		str[0] = '-';
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[buff--] = minus * (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
