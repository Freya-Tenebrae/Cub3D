/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 17:07:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
# define WINDOWS_SIZE_X 2540
# define WINDOWS_SIZE_Y 1440
# define ESC_KEY 65307

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_tiles
{
	int					x_pos;
	int					y_pos;
	char				type;
	struct s_tiles		*next;
}						t_tiles;

typedef struct s_maps
{
	char				*texture_n;
	char				*texture_s;
	char				*texture_e;
	char				*texture_w;
	char				*color_f;
	char				*color_c;
	int					x_lenght;
	int					y_lenght;
	double				x_pos;
	double				y_pos;
	unsigned short		angle;
	int					status_game;
	int					n_frame;
	void				*mlx;
	void				*mlx_win;
	t_tiles				*tiles;
}						t_maps;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
void	success(t_maps **maps);
void	error(char *str, t_maps **maps);
t_tiles	*init_tile(void);
void	push_tiles_back(t_maps **maps, t_tiles *tiles_to_push);
t_maps	*init_maps(void);
void	free_maps(t_maps **maps);
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
void	affmap(t_maps *maps);

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
