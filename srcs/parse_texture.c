/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:27 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	parse_texture(t_cub_data *data, char *line, char **txt_ptr)
{
	int max;

	max = 0;
	if (*txt_ptr != NULL)
		return (exit_msg(data, "Multiple texture keys"));
	line += 2;
	skip_space(&line);
	while (line[max] != ' ' && line[max] != '\n' && line[max] != '\0'
			&& line[max] != '\t' && line[max] != '\r' && line[max] != '\v')
		max++;
	*txt_ptr = ft_substr(line, 0, max);
	line += max;
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\v'
				&& *line != '\n' && *line != '\r')
			return (exit_msg(data, "Unvalid char in texture element"));
		line++;
	}
}
