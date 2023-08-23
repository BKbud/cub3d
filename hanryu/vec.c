/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:45:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/22 14:40:02 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec2	vec_rot(t_vec2 vec, double theta)
{
	t_vec2	new;

	new.x = cos(theta) * vec.x - sin(theta) * vec.y;
	new.y = sin(theta) * vec.x + cos(theta) * vec.y;
	return (new);
}

double	vec_dis(t_vec2 vec1, t_vec2 vec2)
{
	return (sqrt(pow(vec2.x - vec1.x, 2.0) + pow(vec2.y - vec1.y, 2.0)));
}
