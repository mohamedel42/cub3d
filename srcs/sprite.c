/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/12/29 13:11:14 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	dist_next(t_cub_data *data)
{
	int i;

	i = -1;
	while (++i < data->sprite.nbr_spr)
	{
		data->sprite.order[i] = i;
		data->sprite.dist[i] = ((data->ray.pos_x - data->s_coords[i].x) *
				(data->ray.pos_x - data->s_coords[i].x)
					+ (data->ray.pos_y - data->s_coords[i].y)
					* (data->ray.pos_y - data->s_coords[i].y));
	}
}

void	dist(t_cub_data *data)
{
	int		i;
	int		j;
	double	tmp;

	dist_next(data);
	i = -1;
	while (++i < data->sprite.nbr_spr)
	{
		j = -1;
		while (++j < data->sprite.nbr_spr - 1)
		{
			if (data->sprite.dist[j] < data->sprite.dist[j + 1])
			{
				tmp = data->sprite.dist[j];
				data->sprite.dist[j] = data->sprite.dist[j + 1];
				data->sprite.dist[j + 1] = tmp;
				tmp = data->sprite.order[j];
				data->sprite.order[j] = data->sprite.order[j + 1];
				data->sprite.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	perform_sprite_next(t_cub_data *data)
{
	data->sprite.sprite_height = abs((int)(data->res_y
		/ (data->sprite.transform_y)));
	data->sprite.draw_start_y = -data->sprite.sprite_height
		/ 2 + data->res_y / 2;
	if (data->sprite.draw_start_y < 0)
		data->sprite.draw_start_y = 0;
	data->sprite.draw_end_y = data->sprite.sprite_height
		/ 2 + data->res_y / 2;
	if (data->sprite.draw_end_y >= data->res_y)
		data->sprite.draw_end_y = data->res_y;
	data->sprite.sprite_width = abs((int)(data->res_y
		/ (data->sprite.transform_y)));
	data->sprite.draw_start_x = -data->sprite.sprite_width
		/ 2 + data->sprite.sprite_screen_x;
	if (data->sprite.draw_start_x < 0)
		data->sprite.draw_start_x = 0;
	data->sprite.draw_end_x = data->sprite.sprite_width
		/ 2 + data->sprite.sprite_screen_x;
	if (data->sprite.draw_end_x >= data->res_x)
		data->sprite.draw_end_x = data->res_x;
}

void	perform_sprite(t_cub_data *data, int i)
{
	data->sprite.sprite_x = data->s_coords[data->sprite.order[i]].x
		- data->ray.pos_x;
	data->sprite.sprite_y = data->s_coords[data->sprite.order[i]].y
		- data->ray.pos_y;
	data->sprite.invdet = 1.0 / (data->ray.plane_x * data->ray.dir_y -
		data->ray.dir_x * data->ray.plane_y);
	data->sprite.transform_x = data->sprite.invdet
		* (data->ray.dir_y *
		data->sprite.sprite_x - data->ray.dir_x
			* data->sprite.sprite_y);
	data->sprite.transform_y = data->sprite.invdet
		* (-data->ray.plane_y *
		data->sprite.sprite_x + data->ray.plane_x
			* data->sprite.sprite_y);
	data->sprite.sprite_screen_x = (int)((data->res_x / 2)
		* (1 + data->sprite.transform_x
		/ data->sprite.transform_y));
	perform_sprite_next(data);
}

void	ft_sprite(t_cub_data *data)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	dist(data);
	while (++i < data->sprite.nbr_spr)
	{
		perform_sprite(data, i);
		stripe = data->sprite.draw_start_x;
		while (stripe++ < data->sprite.draw_end_x)
		{
			texx = (int)(256 * (stripe - (-data->sprite.sprite_width / 2 +
				data->sprite.sprite_screen_x)) * data->textures[4].width
					/ data->sprite.sprite_width) / 256;
			if (data->sprite.transform_y > 0 && stripe >= 0
				&& stripe < data->res_x
				&& data->sprite.transform_y < data->sprite.zbuffer[stripe])
			{
				y = data->sprite.draw_start_y;
				draw_sprite(data, y, texx, stripe);
			}
		}
	}
}
