/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:22 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	fill_coords(t_cub_data *data)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	z = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '2')
			{
				data->s_coords[z].x = (double)x + 0.5;
				data->s_coords[z].y = (double)y + 0.5;
				z++;
			}
			y++;
		}
		x++;
	}
}

void	fill_sprite(t_cub_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '2')
				data->sprite.nbr_spr++;
			y++;
		}
		x++;
	}
	if (!(data->s_coords = (t_scoords *)malloc(sizeof(t_scoords)
		* data->sprite.nbr_spr)))
		return (exit_msg(data, "Error malloc sprite"));
	if (!(data->sprite.order = (int *)malloc(sizeof(int)
		* data->sprite.nbr_spr)))
		return (exit_msg(data, "Error malloc sprite"));
	if (!(data->sprite.dist = (double *)malloc(sizeof(double)
		* data->sprite.nbr_spr)))
		return (exit_msg(data, "Error malloc sprite"));
	fill_coords(data);
}
