/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:05:02 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 13:57:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(const char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	sum;

	i = 0;
	minus = 1;
	sum = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum = sum * 10;
		if (minus > 0)
			sum += str[i] - '0';
		else
			sum -= str[i] - '0';
		i++;
	}
	return ((int)sum);
}
