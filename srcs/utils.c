/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:43:05 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi_parse(char **nptr)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*(*nptr) == ' ')
		(*nptr)++;
	while (ft_isdigit(*(*nptr)))
	{
		result = (result * 10) + *(*nptr) - '0';
		(*nptr)++;
	}
	return (sign * result);
}

int		get_max_index(t_cub_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}
