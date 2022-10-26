/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:33 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	parse_line(char *line, t_cub_data *data)
{
	skip_space(&line);
	if (*line == 'R')
		return (parse_resolution(++line, data));
	if (*line == 'N' && *(line + 1) == 'O')
		return (parse_texture(data, line, &data->txt_no));
	if (*line == 'S' && *(line + 1) == 'O')
		return (parse_texture(data, line, &data->txt_so));
	if (*line == 'W' && *(line + 1) == 'E')
		return (parse_texture(data, line, &data->txt_we));
	if (*line == 'E' && *(line + 1) == 'A')
		return (parse_texture(data, line, &data->txt_ea));
	if (*line == 'S')
		return (parse_texture(data, line, &data->txt_sprite));
	if (*line == 'F')
		return (parse_color(data, line, &data->floor));
	if (*line == 'C')
		return (parse_color(data, line, &data->roof));
	if (ft_isdigit(*line))
	{
		parse_map(line, data);
		data->map[get_max_index(data)] = 0;
		return ;
	}
	if (ft_isalnum(*line))
		return (exit_msg(data, "Unknown key code"));
}
