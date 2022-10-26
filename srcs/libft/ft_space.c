/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:41:45 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:15:56 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

void	skip_space(char **line)
{
	while (ft_isspace(*(*line)))
		(*line)++;
}
