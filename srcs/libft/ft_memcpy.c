/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:45:22 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:45:22 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*oct1;
	unsigned char	*oct2;

	if (dst == src || n == 0)
		return (dst);
	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	while (n--)
		*oct1++ = *oct2++;
	return (dst);
}
