/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 12:51:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <math.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
// # define WINDOWS_SIZE_X 2540
// # define WINDOWS_SIZE_Y 1440
// # define WINDOWS_SIZE_X 1920
// # define WINDOWS_SIZE_Y 1080
# define WINDOWS_SIZE_X 1080
# define WINDOWS_SIZE_Y 720
// # define WINDOWS_SIZE_X 720
// # define WINDOWS_SIZE_Y 480
# define TEXTURE_SIZE_X 64
# define TEXTURE_SIZE_Y 64

# define ESC_KEY 65307
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_UP 65364
# define ARROW_DOWN 65362

# define N_TEXTURE 4
# define TEXTURE_WALL_N 0
# define TEXTURE_WALL_E 1
# define TEXTURE_WALL_S 2
# define TEXTURE_WALL_W 3

# define COLOR_WALL_MINIMAP 0x00800080
# define COLOR_PLAYER_MINIMAP 0x000000FF
# define COLOR_COV_MINIMAP 0x0000FFFF

# define MOUSE_ANGLE 0.0005
# define MOUSE_PITCH 1
# define KEY_ANGLE 0.02
# define KEY_MOVE 0.1
# define KEY_PITCH 10

# define N_KEY 8
# define KEY_W 0
# define KEY_A 1
# define KEY_S 2
# define KEY_D 3
# define KEY_UP 4
# define KEY_LEFT 5
# define KEY_DOWN 6
# define KEY_RIGHT 7

# define FOV 0.5

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_tiles
{
	int				x_pos;
	int				y_pos;
	char			type;
	struct s_tiles	*next;
}					t_tiles;

typedef struct s_myimg
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_myimg;

typedef struct s_maps
{
	char			*texture_n;
	char			*texture_s;
	char			*texture_e;
	char			*texture_w;
	char			*color_f;
	char			*color_c;
	int				code_color_f;
	int				code_color_c;
	int				x_lenght;
	int				y_lenght;
	double			x_pos;
	double			y_pos;
	double			angle_h;
	int				pitch;
	int				status_game;
	int				n_frame;
	int				key_pressed[N_KEY];
	void			*mlx;
	void			*mlx_win;
	t_myimg			*img;
	t_myimg			*textures[N_TEXTURE];
	t_tiles			*tiles;
}					t_maps;

typedef struct s_ray
{
	double			ray_direction[2];
	double			actual_position[2];
	int				pointing_position[2];
	double			distance_next_position[2];
	double			delta_distance[2];
	int				next_step_position[2];
	int				side;
	double			perpendicular_distance;
	int				height;
	int				start;
	int				end;
}					t_ray;

typedef struct s_texture
{
	int				texture_number;
	double			position_x_on_wall;
	int				texture_position[2];
	double			step;
	double			pos_start_texture;
	int				number_texture;
}					t_texture;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
void	success(t_maps **maps);
void	error(char *str, t_maps **maps);
void	free_maps(t_maps **maps);
t_tiles	*init_tile(t_maps **maps, char **l);
t_maps	*init_maps(void);
void	push_tiles_back(t_maps **maps, t_tiles *tiles_to_push);
void	get_map(t_maps **maps, const char *map_path);
void	add_id(t_maps **maps, char **l);
void	add_id_north(t_maps **maps, char **l, int i);
void	add_id_south(t_maps **maps, char **l, int i);
void	add_id_east(t_maps **maps, char **l, int i);
void	add_id_west(t_maps **maps, char **l, int i);
void	add_id_floor_color(t_maps **maps, char **l, int i);
void	add_id_ceiling_color(t_maps **maps, char **l, int i);
void	add_line_on_map(t_maps **maps, char **l, int n_line);
char	*dup_path_value(char **l, int i, t_maps **maps);
void	check_map_validity(t_maps **maps);
void	check_validity_textures(t_maps **maps);
void	check_color_value(t_maps **maps);
void	affmap(t_maps *maps);
void	aff_position(t_maps *maps);
void	load_textures(t_maps **maps);
void	event_hook(t_maps **maps);
void	event_hook_key(t_maps **maps);
void	event_hook_mouse(t_maps **maps);
void	move(t_maps **maps);
int		is_out_of_wall(t_maps **maps, double x, double y);
void	change_pitch(int *pitch, int value);
void	rotate(double *angle, double value);
void	draw_scene(t_maps **maps);
void	draw_pov(t_maps **maps);
void	pre_calc_raycasting_1(t_maps *maps, t_ray *ray, int count_x);
void	pre_calc_raycasting_2(t_maps *maps, t_ray *ray, t_texture *text);
void	draw_minimap(t_maps **maps);

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
