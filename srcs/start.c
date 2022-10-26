/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:53 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:45:44 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cub_data *data)
{
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->res_x, data->res_y, "Cub3D")))
		exit_msg(data, "mlx_new_window failed");
	mlx_hook(data->win_ptr, 33, 1L << 17, exit_prog, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx_ptr, go_raycasting, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx_ptr);
}

void	start_game(t_cub_data *data)
{
	if (!(data->mlx_ptr = mlx_init()))
		return (exit_msg(data, "mlx_init failed"));
	if (data->roof == -1 || data->floor == -1)
		return (exit_msg(data, "Bad colors"));
	check_res_max_size(data);
	check_map(data);
	fill_player(data);
	replace_space_wall(data);
	adjust_map(data);
	init_var(data);
	fill_sprite(data);
	fill_textures(data);
	if (!(data->img.img = mlx_new_image(data->mlx_ptr,
		data->res_x, data->res_y)))
		exit_msg(data, "mlx_new_image failed");
	if (!(data->img.addr = (int *)mlx_get_data_addr(data->img.img,
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian)))
		exit_msg(data, "mlx_get_data_addr failed");
	if (data->save)
		go_raycasting(data);
	init_mlx(data);
}
