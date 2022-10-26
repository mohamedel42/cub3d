/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:09:08 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:48:40 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new_ptr;
	size_t	current_size;

	if (ptr == NULL)
		return (malloc(size));
	current_size = sizeof(ptr);
	if (size <= current_size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, current_size);
	free(ptr);
	return (new_ptr);
}
