/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:40:56 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:18:36 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	fill_this_shit(t_cub_data *data, int index, int max_char)
{
	char	*line;
	int		y;

	if (!(line = (char*)malloc(max_char + 1)))
		return (exit_msg(data, "Error malloc map"));
	y = 0;
	while (data->map[index][y])
	{
		line[y] = data->map[index][y];
		y++;
	}
	while (y < max_char)
	{
		line[y] = '1';
		y++;
	}
	line[y] = 0;
	free(data->map[index]);
	data->map[index] = line;
}

void	fill_wall_in_map(t_cub_data *data, int max_char)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		if ((int)ft_strlen(data->map[x]) < max_char)
			fill_this_shit(data, x, max_char);
		x++;
	}
}

void	adjust_map(t_cub_data *data)
{
	int	x;
	int	curr_char;
	int	max_char;

	x = 1;
	curr_char = 0;
	max_char = ft_strlen(data->map[0]);
	while (data->map[x])
	{
		curr_char = ft_strlen(data->map[x]);
		if (curr_char > max_char)
			max_char = curr_char;
		x++;
	}
	fill_wall_in_map(data, max_char);
}
