/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:15:56 by bojung            #+#    #+#             */
/*   Updated: 2023/08/24 17:49:40 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_color(t_data *data, t_cpoint inter, int wy, int y_start, int y_end)
{
	int			tx;
	int			ty;
	t_texture	*tex;

	if (inter.c_dir == 'E')
	{
		tex = data->e_tex;
		tx = (int)((1 - (inter.pos.y - floor(inter.pos.y))) * tex->width);
	}
	if (inter.c_dir == 'W')
	{
		tex = data->w_tex;
		tx = (int)((inter.pos.y - floor(inter.pos.y)) * tex->width);
	}
	if (inter.c_dir == 'N')
	{
		tex = data->n_tex;
		tx = (int)((1 - (inter.pos.x - floor(inter.pos.x))) * tex->width);
	}
	if (inter.c_dir == 'S')
	{
		tex = data->s_tex;
		tx = (int)((inter.pos.x - floor(inter.pos.x)) * tex->width);
	}
	ty = (int)((double)(wy - y_start) * tex->height / (y_end - y_start));
	return (tex->addr[tex->line_length / (tex->bits_per_pixel / 8) * ty + tx]);
}

t_texture	*new_tex(t_data *data, char *filename)
{
	t_texture *tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		return (NULL);
	tex->img = mlx_xpm_file_to_image(data->mlx, filename, &tex->width, &tex->height);
	if (!tex->img)
	{
		free(tex);
		return (NULL);
	}
	tex->addr = (unsigned int*)mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
		&tex->line_length, &tex->endian);
	if (!tex->addr)
	{
		free(tex->img);
		free(tex);
		return (NULL);
	}
	return (tex);
}

void	init_tex_wall(t_data *data, t_game *game)
{
	data->n_tex = new_tex(data, game->n_texture);
	data->s_tex = new_tex(data, game->s_texture);
	data->e_tex = new_tex(data, game->e_texture);
	data->w_tex = new_tex(data, game->w_texture);
	if (!data->n_tex || !data->s_tex || !data->e_tex || !data->w_tex)
		print_err("File does not exist\n");
}
