/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:45 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 00:10:29 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_var(t_cub_data *data)
{
	if (!(data->sprite.zbuffer = (double *)malloc(sizeof(double)
		* data->res_x)))
		return (exit_msg(data, "Error malloc init"));
	data->ray.dir_x = -1;
	data->ray.plane_y = 0.66;
	data->ray.pos_x = (double)data->player[0] + 0.5;
	data->ray.pos_y = (double)data->player[1] + 0.5;
	if (data->letter == 'N')
		data->ray.dir_x = -1;
	if (data->letter == 'S')
		data->ray.dir_x = 1;
	if (data->letter == 'E')
		data->ray.dir_y = 1;
	if (data->letter == 'W')
		data->ray.dir_y = -1;
	if (data->letter == 'N')
		data->ray.plane_y = 0.66;
	if (data->letter == 'S')
		data->ray.plane_y = -0.66;
	if (data->letter == 'E')
		data->ray.plane_x = 0.66;
	if (data->letter == 'W')
		data->ray.plane_x = -0.66;
}

int		go_raycasting(t_cub_data *data)
{
	int x;

	x = 0;
	while (x < data->res_x)
	{
		init_ray(data, x);
		draw_columns(data, x);
		data->sprite.zbuffer[x] = data->ray.perp_wall_dist;
		x++;
	}
	ft_sprite(data);
	if (data->save)
		create_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	forward_back(data);
	left_right(data);
	rotate_right_left(data);
	return (0);
}

void	check_args(t_cub_data *data, int c, char **v)
{
	if (c > 3)
		return (exit_msg(data, "Invalid number of arguments"));
	if (v[2] != NULL && ft_strncmp(v[2], "--save", 7) == 0)
		data->save = 1;
}

void	init_data(t_cub_data *data)
{
	ft_bzero(data, sizeof(t_cub_data));
	data->floor = -1;
	data->roof = -1;
}

int		main(int c, char **v)
{
	int			fd;
	char		*line;
	t_cub_data	data;

	(void)c;
	init_data(&data);
	fd = open(v[1], O_RDONLY);
	if (read(fd, 0, 0) < 0)
	{
		close(fd);
		exit_msg(&data, "File don't exist");
	}
	if (!check_extension(v[1]))
		exit_msg(&data, "Bad file extension");
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(line, &data);
		free(line);
		line = NULL;
	}
	close(fd);
	check_args(&data, c, v);
	start_game(&data);
	return (0);
}
