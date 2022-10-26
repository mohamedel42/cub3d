/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:16 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:25:19 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_res_max_size(t_cub_data *data)
{
	int resx;
	int resy;

	resx = 0;
	resy = 0;
	if (data->res_x <= 0 || data->res_y <= 0)
		return (exit_msg(data, "Bad resolution bitch"));
	if (data->res_x >= 2147483647 || data->res_y >= 2147483647)
		return (exit_msg(data, "Bad resolution bitch"));
	mlx_get_screen_size(data->mlx_ptr, &resx, &resy);
	data->res_x > resx ? data->res_x = resx : data->res_x;
	data->res_y > resy ? data->res_y = resy : data->res_y;
}

void	parse_resolution(char *line, t_cub_data *data)
{
	if (data->res_x != 0 || data->res_y != 0)
		return (exit_msg(data, "Multiple resolution key."));
	data->res_x = ft_atoi_parse(&line);
	skip_space(&line);
	data->res_y = ft_atoi_parse(&line);
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\v'
				&& *line != '\n' && *line != '\r')
			return (exit_msg(data, "Unvalid char in resolution element"));
		line++;
	}
}
