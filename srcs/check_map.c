/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:40:51 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:16:28 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_top_bottom(t_cub_data *data, int max)
{
	int	y;

	y = 0;
	while (data->map[0][y])
	{
		if (data->map[0][y] != '1')
			return (exit_msg(data, "Map not closed"));
		y++;
	}
	y = 0;
	while (data->map[max - 1][y])
	{
		if (data->map[max - 1][y] != '1')
			return (exit_msg(data, "Map not closed"));
		y++;
	}
}

void	check_middle(t_cub_data *data, int max)
{
	int x;
	int y;
	int max_str;

	x = 1;
	while (x < (max - 1))
	{
		y = 0;
		max_str = 0;
		while (data->map[x][y])
		{
			max_str = ft_strlen(data->map[x]);
			if (data->map[x][0] != '1'
					|| data->map[x][max_str - 1] != '1')
				return (exit_msg(data, "Map not closed"));
			y++;
		}
		x++;
	}
}

void	check_letters(t_cub_data *data)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while ((c = data->map[x][y]))
		{
			if (c != '0' && c != '1' && !ft_isspace(c) &&
					c != '2' && c != 'W' &&
					c != 'S' && c != 'E' &&
					c != 'N')
				return (exit_msg(data, "Bad characters in map"));
			y++;
		}
		x++;
	}
}

int		check_extension(char *file)
{
	int x;

	x = 0;
	while (file[x])
	{
		if (file[x] == '.' && file[x + 1] == 'c'
				&& file[x + 2] == 'u' && file[x + 3] == 'b'
				&& file[x + 4] == 0)
			return (1);
		x++;
	}
	return (0);
}

void	check_map(t_cub_data *data)
{
	int	max;

	max = get_max_index(data);
	check_top_bottom(data, max);
	check_middle(data, max);
	check_letters(data);
}
