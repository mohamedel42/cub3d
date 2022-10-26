/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:48:11 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:48:17 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_error_free(char *garbage, char *buffer)
{
	if (garbage)
	{
		free(garbage);
		garbage = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (-1);
}

static int	ft_end_of_reading(char **garbage, char **line)
{
	if (*garbage != NULL)
		*line = ft_strdup(*garbage);
	else
		*line = ft_strdup("");
	free(*garbage);
	*garbage = NULL;
	return (0);
}

static int	ft_update_buffer(char **garbage, char **line)
{
	int		index;
	char	*tmp;

	index = ft_check_line(*garbage);
	if (index == -1)
		return (ft_end_of_reading(garbage, line));
	(*garbage)[index] = 0;
	if (!(*line = ft_strdup(*garbage)))
		return (ft_error_free(*garbage, NULL));
	tmp = *garbage;
	if (!(*garbage = ft_strdup(&(*garbage)[index + 1])))
		return (ft_error_free(*garbage, NULL));
	free(tmp);
	tmp = NULL;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*garbage;
	char		*buffer;
	int			end;

	end = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 0 ||
			!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (ft_check_line(garbage) == -1
			&& (end = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[end] = 0;
		if (!(garbage = ft_strjoin_gnl(garbage, buffer)))
			return (ft_error_free(garbage, buffer));
	}
	free(buffer);
	if (end < 0)
		return (-1);
	return (ft_update_buffer(&garbage, line));
}
