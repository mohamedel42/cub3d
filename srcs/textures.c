/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:59 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	ft_get_texture_adress(t_cub_data *data)
{
	data->textures[0].addr = (int *)mlx_get_data_addr(data->textures[0].img,
		&data->textures[0].bits_per_pixel,
		&data->textures[0].line_length, &data->textures[0].endian);
	data->textures[1].addr = (int *)mlx_get_data_addr(data->textures[1].img,
		&data->textures[1].bits_per_pixel,
		&data->textures[1].line_length, &data->textures[1].endian);
	data->textures[2].addr = (int *)mlx_get_data_addr(data->textures[2].img,
		&data->textures[2].bits_per_pixel,
		&data->textures[2].line_length, &data->textures[2].endian);
	data->textures[3].addr = (int *)mlx_get_data_addr(data->textures[3].img,
		&data->textures[3].bits_per_pixel,
		&data->textures[3].line_length, &data->textures[3].endian);
	data->textures[4].addr = (int *)mlx_get_data_addr(data->textures[4].img,
		&data->textures[4].bits_per_pixel,
		&data->textures[4].line_length, &data->textures[4].endian);
}

void	fill_textures(t_cub_data *data)
{
	if (!(data->textures[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->txt_no, &(data->textures[0].width),
		&(data->textures[0].height))))
		return (exit_msg(data, "Error when fill NO textures"));
	if (!(data->textures[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->txt_so, &(data->textures[1].width),
		&(data->textures[1].height))))
		return (exit_msg(data, "Error when fill SO textures"));
	if (!(data->textures[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->txt_we, &(data->textures[2].width),
		&(data->textures[2].height))))
		return (exit_msg(data, "Error when fill WE textures"));
	if (!(data->textures[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->txt_ea, &(data->textures[3].width),
		&(data->textures[3].height))))
		return (exit_msg(data, "Error when fill EA textures"));
	if (!(data->textures[4].img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->txt_sprite, &(data->textures[4].width),
		&(data->textures[4].height))))
		return (exit_msg(data, "Error when fill SPRITE textures"));
	ft_get_texture_adress(data);
}
