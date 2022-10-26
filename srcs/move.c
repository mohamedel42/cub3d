/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:57 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	rotate_left(t_cub_data *data, double olddirx)
{
	double oldplanex;

	if (data->img.rotate_left == 1)
	{
		olddirx = data->ray.dir_x;
		oldplanex = data->ray.plane_x;
		data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed / 2) -
			data->ray.dir_y * sin(data->ray.rot_speed / 2);
		data->ray.dir_y = olddirx * sin(data->ray.rot_speed / 2) +
			data->ray.dir_y * cos(data->ray.rot_speed / 2);
		data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed / 2) -
			data->ray.plane_y * sin(data->ray.rot_speed / 2);
		data->ray.plane_y = oldplanex * sin(data->ray.rot_speed / 2) +
			data->ray.plane_y * cos(data->ray.rot_speed / 2);
	}
}

void	rotate_right_left(t_cub_data *data)
{
	double oldplanx;
	double olddirx;

	oldplanx = data->ray.plane_x;
	olddirx = data->ray.dir_x;
	if (data->img.rotate_right == 1)
	{
		data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed / 2) -
			data->ray.dir_y * sin(-data->ray.rot_speed / 2);
		data->ray.dir_y = olddirx * sin(-data->ray.rot_speed / 2) +
			data->ray.dir_y * cos(-data->ray.rot_speed / 2);
		data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed / 2)
			- data->ray.plane_y * sin(-data->ray.rot_speed / 2);
		data->ray.plane_y = oldplanx * sin(-data->ray.rot_speed / 2) +
			data->ray.plane_y * cos(-data->ray.rot_speed / 2);
	}
	rotate_left(data, olddirx);
}

void	forward_back(t_cub_data *data)
{
	if (data->img.forward == 1)
	{
		if (data->map[(int)(data->ray.pos_x + (data->ray.dir_x *
			data->ray.move_speed * 2))]
			[(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if (data->map[(int)(data->ray.pos_x)][(int)(data->ray.pos_y +
					(data->ray.dir_y * data->ray.move_speed * 2))] == '0')
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	}
	if (data->img.back == 1)
	{
		if (data->map[(int)(data->ray.pos_x - (data->ray.dir_x *
			data->ray.move_speed * 2))]
			[(int)(data->ray.pos_y)] == '0')
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
		if (data->map[(int)(data->ray.pos_x)][(int)(data->ray.pos_y -
					(data->ray.dir_y * data->ray.move_speed * 2))] == '0')
			data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	}
}

void	left_right(t_cub_data *data)
{
	if (data->img.right == 1)
	{
		if (data->map[(int)(data->ray.pos_x + data->ray.dir_y *
					(data->ray.move_speed * 2))][(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_y * data->ray.move_speed;
		if (data->map[(int)data->ray.pos_x][(int)(data->ray.pos_y -
					data->ray.dir_x *
					(data->ray.move_speed * 2))] == '0')
			data->ray.pos_y -= data->ray.dir_x * data->ray.move_speed;
	}
	if (data->img.left == 1)
	{
		if (data->map[(int)(data->ray.pos_x - data->ray.dir_y *
					(data->ray.move_speed * 2))][(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_y * data->ray.move_speed;
		if (data->map[(int)data->ray.pos_x][(int)(data->ray.pos_y +
					data->ray.dir_x *
					(data->ray.move_speed * 2))] == '0')
			data->ray.pos_y += data->ray.dir_x * data->ray.move_speed;
	}
}
