/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:45:03 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:11:58 by hanryu           ###   ########.fr       */
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

t_vec2	vec_plus(t_vec2 vec1, t_vec2 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	return (vec1);
}

t_vec2	vec_mul(t_vec2 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	return (vec);
}
