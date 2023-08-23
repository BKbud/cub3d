/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:49:21 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/07 14:22:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	str_len(int n)
{
	if (!n)
		return (0);
	return (1 + str_len(n / 10));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	int		buff;
	int		buff_cpy;
	int		minus;

	if (n == 0)
		write(fd, "0", 1);
	buff = str_len(n);
	buff_cpy = buff;
	minus = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		minus = -1;
	}
	while (0 < buff--)
	{
		arr[buff] = minus * (n % 10) + '0';
		n = n / 10;
	}
	write(fd, arr, buff_cpy);
}
