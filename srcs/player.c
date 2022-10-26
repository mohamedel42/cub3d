/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:19:36 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:48:12 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_player(t_cub_data *data)
{
	int	x;
	int	y;
	int	nbr_players;

	nbr_players = 0;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (ft_isalpha(data->map[x][y]))
			{
				nbr_players += 1;
				data->player[0] = x;
				data->player[1] = y;
				data->letter = data->map[x][y];
				data->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	if (nbr_players > 1 || nbr_players == 0)
		return (exit_msg(data, "There can be only one player"));
}
