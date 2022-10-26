/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:47:50 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:47:50 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	*str = 0;
	i = start;
	j = 0;
	while (len > 0)
	{
		str[j] = s[i];
		i++;
		j++;
		len--;
	}
	str[j] = 0;
	return (str);
}
