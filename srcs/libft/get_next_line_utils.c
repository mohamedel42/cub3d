/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:48:04 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:48:05 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	char	*address_to_free;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	if (!(ptr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	i = -1;
	address_to_free = s1;
	while (*s1)
		ptr[++i] = *s1++;
	while (*s2)
		ptr[++i] = *s2++;
	ptr[++i] = 0;
	if (address_to_free != NULL)
		free(address_to_free);
	address_to_free = NULL;
	return (ptr);
}

int		ft_check_line(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
