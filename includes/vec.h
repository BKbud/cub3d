/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:37:30 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/24 14:05:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

t_vec2	vec_rot(t_vec2 vec, double theta);
double	vec_dis(t_vec2 vec1, t_vec2 vec2);
t_vec2	vec_plus(t_vec2 vec1, t_vec2 vec2);
t_vec2	vec_mul(t_vec2 vec, double t);

#endif