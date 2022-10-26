/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:40:27 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_ray_next(t_cub_data *data)
{
	if (data->ray.ray_dir_x == 0)
		data->ray.delta_dist_y = 0;
	else if (data->ray.ray_dir_y == 0)
		data->ray.delta_dist_y = 1;
	else
		data->ray.delta_dist_y = sqrt(1 + (data->ray.ray_dir_x *
					data->ray.ray_dir_x) / (data->ray.ray_dir_y *
						data->ray.ray_dir_y));
	get_side_dist(data);
}

void	init_ray(t_cub_data *data, int x)
{
	data->ray.camera_x = 2 * x / (float)data->res_x - 1;
	data->ray.ray_dir_x = data->ray.dir_x +
		data->ray.plane_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y +
		data->ray.plane_y * data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.hit = 0;
	data->ray.perp_wall_dist = 0;
	data->ray.move_speed = 0.06;
	data->ray.rot_speed = 0.033 * 1.8;
	if (data->ray.ray_dir_y == 0)
		data->ray.delta_dist_x = 0;
	else if (data->ray.ray_dir_x == 0)
		data->ray.delta_dist_x = 1;
	else
		data->ray.delta_dist_x = sqrt(1 + (data->ray.ray_dir_y
					* data->ray.ray_dir_y) / (data->ray.ray_dir_x *
						data->ray.ray_dir_x));
	init_ray_next(data);
}

void	get_side_dist(t_cub_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pos_x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pos_x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pos_y)
			* data->ray.delta_dist_y;
	}
	hit_wall(data);
}

void	hit_wall(t_cub_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.map_x][data->ray.map_y] == '1')
			data->ray.hit = 1;
	}
	dist_ray_to_wall(data);
}

void	dist_ray_to_wall(t_cub_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = ((double)data->ray.map_x - \
				data->ray.pos_x + (1 - (double)data->ray.
					step_x) / 2) / data->ray.ray_dir_x;
	else
		data->ray.perp_wall_dist = ((double)data->ray.map_y - \
				data->ray.pos_y + (1 - (double)data->ray.
					step_y) / 2) / data->ray.ray_dir_y;
	data->ray.line_height = (int)(data->res_y / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + data->res_y / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + data->res_y / 2;
	if (data->ray.draw_end >= data->res_y)
		data->ray.draw_end = data->res_y - 1;
}
