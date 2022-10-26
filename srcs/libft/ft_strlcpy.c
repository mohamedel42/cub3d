/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:47:16 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:47:16 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t size;

	if (!dst || !src)
		return (0);
	i = 0;
	size = 0;
	while (src[size])
		size++;
	if (!n)
		return (size);
	while (src[i] && (i < n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (size);
}
