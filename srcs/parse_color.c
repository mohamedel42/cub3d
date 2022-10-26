/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:02 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:44:44 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	compute_colors(int *color_ptr, int *colors)
{
	int x;
	int value;

	x = 0;
	value = 0;
	while (x < 3)
	{
		value = value * (ft_power(10, ft_nbrlen(colors[x]))) + colors[x];
		x++;
	}
	*color_ptr = value;
}

void	check_colors_nbr(t_cub_data *data, int *color_ptr, int *colors)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
			return (exit_msg(data, "Invalid rgb color"));
		i++;
	}
	compute_colors(color_ptr, colors);
}

void	parse_color(t_cub_data *data, char *line, int *color_ptr)
{
	int i;
	int nbrs[3];

	i = 0;
	ft_bzero(nbrs, 3);
	if (*color_ptr != -1)
		return (exit_msg(data, "Multiple color key"));
	line++;
	while (*line && i < 3)
	{
		if (ft_isspace(*line))
			skip_space(&line);
		if (i >= 3)
			return (exit_msg(data, "Error in color element"));
		if (ft_isdigit(*line))
		{
			nbrs[i] = ft_atoi_parse(&line);
			i++;
		}
		if (!ft_isdigit(*line) && !ft_isspace(*line) && *line != ','
			&& *line != 0)
			return (exit_msg(data, "Error in color element"));
		line++;
	}
	check_colors_nbr(data, color_ptr, nbrs);
}
