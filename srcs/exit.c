/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:21 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	exit_msg(t_cub_data *data, char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit_prog(data);
}

void	free_sprite(t_cub_data *data)
{
	if (data->sprite.dist)
		free(data->sprite.dist);
	if (data->sprite.order)
		free(data->sprite.order);
	if (data->s_coords)
		free(data->s_coords);
	if (data->sprite.zbuffer)
		free(data->sprite.zbuffer);
}

void	free_all(t_cub_data *data)
{
	int x;

	x = -1;
	if (data->map != NULL && data->map[x])
	{
		while (data->map[++x])
			free(data->map[x]);
		free(data->map);
	}
	if (data->txt_no)
		free(data->txt_no);
	if (data->txt_so)
		free(data->txt_so);
	if (data->txt_we)
		free(data->txt_we);
	if (data->txt_ea)
		free(data->txt_ea);
	if (data->txt_sprite)
		free(data->txt_sprite);
	free_sprite(data);
}

int		exit_prog(t_cub_data *data)
{
	free_all(data);
	if (data->img.img)
		mlx_destroy_image(data->mlx_ptr, data->img.img);
	if (data->textures[0].img)
		mlx_destroy_image(data->mlx_ptr, data->textures[0].img);
	if (data->textures[1].img)
		mlx_destroy_image(data->mlx_ptr, data->textures[1].img);
	if (data->textures[2].img)
		mlx_destroy_image(data->mlx_ptr, data->textures[2].img);
	if (data->textures[3].img)
		mlx_destroy_image(data->mlx_ptr, data->textures[3].img);
	if (data->textures[4].img)
		mlx_destroy_image(data->mlx_ptr, data->textures[4].img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_putstr_fd("Ciao !", 1);
	exit(0);
}
