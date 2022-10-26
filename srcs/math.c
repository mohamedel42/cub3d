/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:50 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/28 15:41:51 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (ft_power(nb, power - 1) * nb);
}

int	ft_nbrlen(long nbr)
{
	int		count;

	count = 1;
	while ((nbr / ft_power(10, count)) != 0)
		count++;
	return (count);
}
