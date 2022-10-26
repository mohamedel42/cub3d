/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:47:03 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:47:03 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen((char *)s1) + 1);
	size = 0;
	while (str[size])
		size++;
	while (*s2)
	{
		str[size] = *s2;
		s2++;
		size++;
	}
	str[size] = 0;
	return (str);
}
