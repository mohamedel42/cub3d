/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:10 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:48:01 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_nbr_index(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i + 1);
}

char	**cpy_map(char *line, t_cub_data *data)
{
	int		size;
	int		i;
	char	**new_tab;

	i = 0;
	size = get_nbr_index(data->map);
	if (!(new_tab = (char**)malloc(sizeof(char*) * (size + 1))))
		exit_msg(data, "Error malloc map");
	while (data->map[i])
	{
		new_tab[i] = ft_strdup(data->map[i]);
		free(data->map[i]);
		i++;
	}
	new_tab[i] = ft_strdup(line);
	new_tab[i + 1] = 0;
	free(data->map);
	return (new_tab);
}

int		have_char(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (ft_isalnum(line[x]))
			return (1);
		x++;
	}
	return (0);
}

void	parse_map(char *line, t_cub_data *data)
{
	if (!have_char(line))
		return ;
	if (data->map == NULL)
	{
		if (!(data->map = (char**)malloc(sizeof(char*) + 1)))
			return (exit_msg(data, "Error malloc map"));
		data->map[0] = ft_strdup(line);
		data->map[1] = 0;
		return ;
	}
	data->map = cpy_map(line, data);
	return ;
}

void	replace_space_wall(t_cub_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (ft_isspace(data->map[x][y]))
				data->map[x][y] = '0';
			y++;
		}
		x++;
	}
}
