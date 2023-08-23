/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:10:52 by hanryu            #+#    #+#             */
/*   Updated: 2023/08/23 18:30:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vec2	rotate_ray_h(t_vec2 p_dir, int i)
{
	double	theta;

	theta = (deg2rad(FOV) / (W_X - 1)) * (i - ((double)(W_X + 1) / 2));
	return (vec_rot(p_dir, theta));
}

static t_cpoint	raycast_single_close(t_vec2 pos, t_cpoint inter_x, t_cpoint inter_y)
{
	if (!inter_x.c_dir)
		return (inter_y);
	if (!inter_y.c_dir)
		return (inter_x);
	if (vec_dis(inter_x.pos, pos) < vec_dis(inter_y.pos, pos))
		return (inter_x);
	return (inter_y);
}

t_cpoint	raycast_single(t_vec2 pos, t_vec2 dir, t_game *game)
{
	t_cpoint	inter_x;
	t_cpoint	inter_y;

	ft_memset(&inter_x, 0, sizeof(t_cpoint));
	ft_memset(&inter_y, 0, sizeof(t_cpoint));
	if (!is_zero(dir.x))
		inter_x = raycast_single_step_x(pos, dir, game);
	if (!is_zero(dir.y))
		inter_y = raycast_single_step_y(pos, dir, game);
	return (raycast_single_close(pos, inter_x, inter_y));
}

void	raycast(t_player *player, t_game *game, t_data *data)
{
	int	i;

	i = 0;
	while (i < W_X)
	{
		draw_wall(player, game, data, i);
		i++;
	}
}
