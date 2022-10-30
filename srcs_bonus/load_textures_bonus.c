/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:18:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	load_entities(t_maps **maps, int texture_size_x, int texture_size_y)
{
	(*maps)->textures_entities->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, PATH_TEXTURES_ENTITIES, \
			&texture_size_x, &texture_size_y);
	if (!(*maps)->textures_entities->img_ptr)
		error("couldn't load entities textures", maps);
	(*maps)->textures_entities->data = \
		(int *)mlx_get_data_addr((*maps)->textures_entities->img_ptr, \
		&((*maps)->textures_entities->bpp), \
		&((*maps)->textures_entities->size_l), \
		&((*maps)->textures_entities->endian));
}

static void	load_wall_ceiling(t_maps **maps, int texture_size_x, \
															int texture_size_y)
{
	(*maps)->textures_wall_floor->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, PATH_TEXTURES_WALL_FLOOR, \
			&texture_size_x, &texture_size_y);
	if (!(*maps)->textures_wall_floor->img_ptr)
		error("couldn't load wall and floor textures", maps);
	(*maps)->textures_wall_floor->data = \
		(int *)mlx_get_data_addr((*maps)->textures_wall_floor->img_ptr, \
		&((*maps)->textures_wall_floor->bpp), \
		&((*maps)->textures_wall_floor->size_l), \
		&((*maps)->textures_wall_floor->endian));
}

void	load_textures(t_maps **maps)
{
	int	texture_size_x;
	int	texture_size_y;

	texture_size_x = TEXTURE_SIZE_X;
	texture_size_y = TEXTURE_SIZE_Y;
	load_entities(maps, texture_size_x, texture_size_y);
	load_wall_ceiling(maps, texture_size_x, texture_size_y);
}
