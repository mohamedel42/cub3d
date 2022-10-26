/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:49:07 by mel-kada          #+#    #+#             */
/*   Updated: 2020/12/29 11:13:05 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 119
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 97

typedef struct	s_scoords
{
	double		x;
	double		y;
}				t_scoords;

typedef struct	s_sprite
{
	int			nbr_spr;
	int			*order;
	double		*dist;
	double		sprite_x;
	double		sprite_y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			sprite_width;
	double		*zbuffer;
}				t_sprite;

typedef struct	s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			width;
	int			height;
}				t_data;

typedef struct	s_texture
{
	int			tex_dir;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_texture;

typedef	struct	s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	int			hit;
	int			texture;
}				t_ray;

typedef struct	s_t_cub_data
{
	int			res_x;
	int			res_y;
	char		*txt_no;
	char		*txt_so;
	char		*txt_we;
	char		*txt_ea;
	char		*txt_sprite;
	int			floor;
	int			roof;
	char		**map;
	int			player[2];
	char		letter;
	void		*mlx_ptr;
	void		*win_ptr;
	int			save;
	t_texture	texture;
	t_data		textures[5];
	t_data		img;
	t_ray		ray;
	t_scoords	*s_coords;
	t_sprite	sprite;
}				t_cub_data;

void			parse_line(char *line, t_cub_data *data);
void			skip_space(char **line);
void			show_data_content(t_cub_data *data);
int				ft_atoi_parse(char **nptr);
int				ft_isspace(int c);
int				get_max_index(t_cub_data *data);
void			check_map(t_cub_data *data);
void			fill_player(t_cub_data *data);
int				draw_columns(t_cub_data *data, int x);
void			draw_texture(t_cub_data *data, int x, int y);
void			init_ray(t_cub_data *data, int x);
void			get_side_dist(t_cub_data *data);
void			hit_wall(t_cub_data *data);
void			dist_ray_to_wall(t_cub_data *data);
void			parse_resolution(char *line, t_cub_data *data);
void			parse_texture(t_cub_data *data, char *line, char **txt_ptr);
void			parse_color(t_cub_data *data, char *line, int *color_ptr);
void			parse_map(char *line, t_cub_data *data);
void			fill_textures(t_cub_data *data);
int				key_press(int keycode, t_cub_data *data);
int				key_release(int keycode, t_cub_data *data);
void			rotate_left(t_cub_data *data, double olddirx);
void			rotate_right_left(t_cub_data *data);
void			forward_back(t_cub_data *data);
void			left_right(t_cub_data *data);
void			fill_sprite(t_cub_data *data);
void			ft_sprite(t_cub_data *data);
void			adjust_map(t_cub_data *data);
int				ft_power(int nb, int power);
int				ft_nbrlen(long nbr);
int				exit_prog(t_cub_data *data);
void			exit_msg(t_cub_data *data, char *str);
int				check_extension(char *file);
void			create_image(t_cub_data *data);
void			check_res_max_size(t_cub_data *data);
void			start_game(t_cub_data *data);
int				go_raycasting(t_cub_data *data);
void			draw_sprite(t_cub_data *data, int y, int texx, int stripe);
void			init_var(t_cub_data *data);
void			replace_space_wall(t_cub_data *data);

#endif
