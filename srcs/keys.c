/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:54:50 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 10:55:42 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	key_press(int keycode, t_cub_data *data)
{
	if (keycode == FORWARD_W_Z)
		data->img.forward = 1;
	else if (keycode == BACK_S_S)
		data->img.back = 1;
	else if (keycode == LEFT_A_Q)
		data->img.left = 1;
	else if (keycode == RIGHT_D_D)
		data->img.right = 1;
	else if (keycode == ROTATE_LEFT)
		data->img.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		data->img.rotate_right = 1;
	return (1);
}

int	key_release(int keycode, t_cub_data *data)
{
	if (keycode == 65307)
		exit_msg(data, "It's the end!!");
	if (keycode == FORWARD_W_Z)
		data->img.forward = 0;
	if (keycode == BACK_S_S)
		data->img.back = 0;
	else if (keycode == LEFT_A_Q)
		data->img.left = 0;
	else if (keycode == RIGHT_D_D)
		data->img.right = 0;
	else if (keycode == ROTATE_LEFT)
		data->img.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		data->img.rotate_right = 0;
	return (1);
}
