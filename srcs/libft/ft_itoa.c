/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:44:20 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:44:21 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int	ft_pwr(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	return (nbr * ft_pwr(nbr, power - 1));
}

static	int	get_size(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while ((n = (n / 10)) != 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	long	nbr;

	i = 0;
	size = get_size(n);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	if (n < 0)
	{
		nbr = (long)n * -1;
		str[i] = '-';
		i++;
	}
	else
		nbr = n;
	while (i < size)
	{
		str[i] = (nbr / ft_pwr(10, size - 1 - i) + 48);
		nbr = nbr % ft_pwr(10, size - 1 - i);
		i++;
	}
	str[i] = 0;
	return (str);
}
