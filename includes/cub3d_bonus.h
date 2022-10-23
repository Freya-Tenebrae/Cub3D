/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/23 07:37:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <math.h>
# include <sys/time.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
/* ******************************* WINDOW SIZE ****************************** */
// # define WINDOWS_SIZE_X 2540
// # define WINDOWS_SIZE_Y 1440
// # define WINDOWS_SIZE_X 1920
// # define WINDOWS_SIZE_Y 1080
# define WINDOWS_SIZE_X 1200
# define WINDOWS_SIZE_Y 900
// # define WINDOWS_SIZE_X 1080
// # define WINDOWS_SIZE_Y 720
// # define WINDOWS_SIZE_X 720
// # define WINDOWS_SIZE_Y 480

/* ****************************** TEXTURE SIZE ***************************** */
# define TEXTURE_SIZE_X 64
# define TEXTURE_SIZE_Y 64

/* ********************************** KEYS ********************************* */
# define ESC_KEY 65307
# define ENTER_KEY 65293
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_UP 65364
# define ARROW_DOWN 65362

/* ******************************* STATUS GAME ****************************** */
# define WAITING 0
# define LOADING 1
# define RUNNING 2
# define GAME_OVER_LOOSE 3
# define GAME_OVER_WIN 4

/* ****************************** TEXTURE PATH ****************************** */
# define PATH_TEXTURES_ENTITIES "data/entities.xpm"
# define PATH_TEXTURES_WALL_FLOOR "data/wallFloorTextures.xpm"
# define PATH_DECOR_POKEMON "data/decor.xpm"

/* ********************************** MAPS ********************************** */
# define N_MAPS 4
# define MAPS_1 "maps/advanced/generic_adventure_1.cub"
# define MAPS_2 "maps/advanced/generic_adventure_2.cub"
# define MAPS_3 "maps/advanced/generic_adventure_3.cub"
# define MAPS_4 "maps/advanced/generic_adventure_4.cub"

/* ********************************** COLOR ********************************* */
# define COLOR_WALL_MINIMAP 0x00800080
# define COLOR_DOOR_MINIMAP 0x00000000
# define COLOR_ENTITIE_MINIMAP 0x00FFFFFF
# define COLOR_ACTOR_UP_MINIMAP 0xFF0068
# define COLOR_ACTOR_DOWN_MINIMAP 0x00FF68
# define COLOR_PLAYER_MINIMAP 0x000000FF
# define COLOR_COV_MINIMAP 0x0000FFFF
# define COLOR_CEILING 0x738585
# define COLOR_FLOOR 0x362E2B
# define COLOR_TEXT 0x00FFFFFF

/* ***************************** MOVEMENT VALUE ***************************** */
# define MOUSE_ANGLE 0.0005
# define MOUSE_PITCH 1
# define KEY_ANGLE 0.02
# define KEY_MOVE 0.1
# define KEY_PITCH 10
# define ACTOR_MOVE 0.05

/* ******************************** ENTITIES ******************************** */
# define N_KEY 8
# define KEY_W 0
# define KEY_A 1
# define KEY_S 2
# define KEY_D 3
# define KEY_UP 4
# define KEY_LEFT 5
# define KEY_DOWN 6
# define KEY_RIGHT 7
# define N_DOOR 7
# define N_SPELL 5
# define N_LIFE 3

/* ********************************** OTHER ********************************* */
# define TIME_DOWN 500
# define N_FRAME 8

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
/* ****************************** FOR GAME VALUE **************************** */
typedef struct s_actor
{
	char			type;
	double			x_pos;
	double			y_pos;
	unsigned int	time_down;
	int				direction;
	struct s_actor	*next;
}					t_actor;

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
	int				status_game;
	int				n_maps;
	int				x_lenght;
	int				y_lenght;
	double			x_pos;
	double			y_pos;
	double			angle_h;
	double			movement_factor;
	double			z_buffer[WINDOWS_SIZE_X];
	int				pitch;
	int				n_frame;
	int				key_pressed[N_KEY];
	int				spells[N_SPELL];
	int				cristal_get[N_DOOR];
	int				life;
	void			*mlx;
	void			*mlx_win;
	t_myimg			*img;
	t_myimg			*textures_entities;
	t_myimg			*textures_wall_floor;
	t_tiles			*tiles;
	t_actor			*actor;
}					t_maps;

/* ****************************** FOR RAYCASTING **************************** */
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

typedef struct s_floor
{
	double			direction[2];
	double			plane[2];
	double			ray_direction_rmv[2];
	double			ray_direction_add[2];
	int				vertical_position_from_center;
	double			row_distances;
	double			delta_distance[2];
	double			floor[2];
	int				t[2];
	int				count_x;
	int				count_y;
}					t_floor;

typedef struct s_entitie
{
	double			direction[2];
	double			plane[2];
	double			pos_absolute[2];
	double			pos_relative[2];
	double			depth;
	int				x_pos_on_screen;
	int				height_and_width;
	int				start[2];
	int				end[2];
}					t_entitie;

/* ******************************* FOR TEXTURES ***************************** */
typedef struct s_texture
{
	double			position_x_on_wall;
	int				texture_position[2];
	double			step;
	double			pos_start_texture;
	int				number_texture;
}					t_texture;

typedef struct s_texture_entitie
{
	double			step;
	double			pos_start_texture[2];
	int				texture_position[2];
	int				number_texture;
}					t_texture_entitie;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
/* ********************************** MAIN ********************************** */
int				main(void);

/* ********************************** EXIT ********************************** */
void			success(t_maps **maps);
void			game_over(t_maps **maps);
void			win(t_maps **maps);
void			error(char *str, t_maps **maps);

/* ************************** INIT AND FREE MEMORY ************************** */
void			free_maps(t_maps **maps);
void			free_for_next_map(t_maps **maps);
t_tiles			*init_tile(t_maps **maps, char **l);
t_actor			*init_actor(t_maps **maps, char **l);
t_maps			*init_maps(void);
void			push_tiles_back(t_maps **maps, t_tiles *tiles_to_push);
void			push_actor_back(t_maps **maps, t_actor *actor_to_push);

/* ********************************* PARSING ******************************** */
void			get_map(t_maps **maps, const char *map_path);
void			add_line_on_map(t_maps **maps, char **l, int n_line);
void			check_map_validity(t_maps **maps);
void			check_validity_textures(t_maps **maps);

/* ****************************** LOAD TEXTURES ***************************** */
void			load_textures(t_maps **maps);

/* ********************************** HOOK ********************************** */
void			event_hook(t_maps **maps);
void			event_hook_key(t_maps **maps);
void			event_hook_mouse(t_maps **maps);

/* ********************************** DRAW ********************************** */
void			draw_scene(t_maps **maps);

/* ******************************* RAY CASTING ****************************** */
void			draw_pov(t_maps **maps);
void			draw_floor(t_maps **maps);
void			draw_entities(t_maps **maps);
void			pre_calc_raycasting_1(t_maps *maps, t_ray *ray, int count_x);
void			pre_calc_raycasting_2(t_maps *maps, t_ray *ray, \
															t_texture *text);
void			sort_actor_from_distance(t_maps **maps);
void			pre_calc_raycasting_entities(t_maps *maps, t_entitie *entitie);
void			get_number_text_and_step_actor(t_entitie *entitie, \
										t_texture_entitie *text, char type);
/* *************************** DRAW MINIMAP & ATH *************************** */
void			draw_minimap(t_maps **maps);
void			draw_actor_minimap(t_maps **maps, t_actor *actor_ptr);
void			draw_player_minimap(t_maps **maps);
void			draw_ath(t_maps **maps);
void			draw_key(t_maps **maps, int i);
int				get_value_with_transparency(int base_color, int new_color, \
														double transparency);

/* ******************************** MOVEMENT ******************************** */
void			move(t_maps **maps);
int				is_out_of_wall(t_maps **maps, double x, double y);
void			change_pitch(int *pitch, int value);
void			rotate(double *angle, double value);

/* ********************************** TIME ********************************** */
unsigned long	get_time(void);
void			get_movement_factor(t_maps **maps);
void			update_frame(t_maps **maps);
void			update_actor(t_maps **maps);
void			update_spell(t_maps **maps);

/* *************************** COLLISION & ACTION *************************** */
void			actor_on_player(t_maps **maps);
int				actor_is_in_wall(t_maps **maps, double x, double y);
void			action_key(t_maps **maps);
void			action_transformation(t_maps **maps);

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
