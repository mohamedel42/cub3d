/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:13 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 13:12:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int		draw_columns(t_cub_data *data, int x)
{
	int y;
	int start_of_floor;

	y = -1;
	data->ray.draw_end = data->res_y - data->ray.draw_start;
	start_of_floor = data->ray.draw_end;
	while (++y < data->ray.draw_start)
		data->img.addr[y * data->img.line_length / 4
			+ x] = data->roof;
	if (y <= data->ray.draw_end)
		draw_texture(data, x, y);
	y = start_of_floor;
	while (++y < data->res_y)
		data->img.addr[y * data->img.line_length / 4 +
			x] = data->floor;
	return (0);
}

void	get_textures_dir(t_cub_data *data)
{
	if (data->ray.side == 0 && data->ray.ray_dir_x < 0)
		data->texture.tex_dir = 0;
	if (data->ray.side == 0 && data->ray.ray_dir_x >= 0)
		data->texture.tex_dir = 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->texture.tex_dir = 2;
	if (data->ray.side == 1 && data->ray.ray_dir_y >= 0)
		data->texture.tex_dir = 3;
	if (data->ray.side == 0)
		data->texture.wall_x = data->ray.pos_y +
			data->ray.perp_wall_dist * data->ray.ray_dir_y;
	else
		data->texture.wall_x = data->ray.pos_x +
			data->ray.perp_wall_dist * data->ray.ray_dir_x;
	data->texture.wall_x -= floor((data->texture.wall_x));
}

void	draw_texture(t_cub_data *data, int x, int y)
{
	y = data->ray.draw_start - 1;
	get_textures_dir(data);
	data->texture.step = 1.0 * data->textures[0].height / data->ray.line_height;
	data->texture.tex_x = (int)(data->texture.wall_x *
		(double)data->textures[data->texture.tex_dir].width);
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->texture.tex_x = data->textures[data->texture.tex_dir].width -
			data->texture.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->texture.tex_x = data->textures[data->texture.tex_dir].width -
			data->texture.tex_x - 1;
	data->texture.tex_pos = (data->ray.draw_start - data->res_y / 2 +
		data->ray.line_height / 2) * data->texture.step;
	while (++y <= data->ray.draw_end)
	{
		data->texture.tex_y = (int)data->texture.tex_pos &
			(data->textures[data->texture.tex_dir].height - 1);
		data->texture.tex_pos += data->texture.step;
		if (y < data->res_y && x < data->res_x)
			data->img.addr[y * data->img.line_length / 4 + x] =
			data->textures[data->texture.tex_dir].addr[data->texture.tex_y *
			data->textures[data->texture.tex_dir].line_length / 4 +
				data->texture.tex_x];
	}
}

void	draw_sprite(t_cub_data *data, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < data->sprite.draw_end_y)
	{
		d = (y) * 256 - data->res_y * 128 +
			data->sprite.sprite_height * 128;
		texy = ((d * data->textures[4].height) /
			data->sprite.sprite_height) / 256;
		if (data->textures[4].addr[texy *
			data->textures[4].line_length / 4 +
				texx] != 0)
		{
			data->img.addr[y * data->img.line_length / 4 + stripe] =
				data->textures[4].addr[texy *
					data->textures[4].line_length /
				4 + texx];
		}
		y++;
	}
}
