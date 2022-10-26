/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:27 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	generate_img(t_cub_data *data, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * data->res_x * data->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &data->res_x, 4);
	write(fd, &data->res_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &data->img.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	create_image(t_cub_data *data)
{
	int	x;
	int	y;
	int	fd;

	y = data->res_y;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		exit_msg(data, "BMP creation failed.");
	generate_img(data, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < data->res_x)
		{
			write(fd, &data->img.addr[y * data->img.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	exit_msg(data, "Image created, gooooood");
}
