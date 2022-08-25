/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/24 13:40:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_wall_n(t_maps **maps, int texture_size_x, int texture_size_y)
{
	((*maps)->textures)[TEXTURE_WALL_N]->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, (*maps)->texture_n, \
			&texture_size_x, &texture_size_y);
	((*maps)->textures)[TEXTURE_WALL_N]->data = \
		(int *)mlx_get_data_addr(((*maps)->textures)[TEXTURE_WALL_N]->img_ptr, \
		&(((*maps)->textures)[TEXTURE_WALL_N]->bpp), \
		&(((*maps)->textures)[TEXTURE_WALL_N]->size_l), \
		&(((*maps)->textures)[TEXTURE_WALL_N]->endian));
}

static void	load_wall_e(t_maps **maps, int texture_size_x, int texture_size_y)
{
	((*maps)->textures)[TEXTURE_WALL_E]->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, (*maps)->texture_e, \
			&texture_size_x, &texture_size_y);
	((*maps)->textures)[TEXTURE_WALL_E]->data = \
		(int *)mlx_get_data_addr(((*maps)->textures)[TEXTURE_WALL_E]->img_ptr, \
		&(((*maps)->textures)[TEXTURE_WALL_E]->bpp), \
		&(((*maps)->textures)[TEXTURE_WALL_E]->size_l), \
		&(((*maps)->textures)[TEXTURE_WALL_E]->endian));
}

static void	load_wall_s(t_maps **maps, int texture_size_x, int texture_size_y)
{
	((*maps)->textures)[TEXTURE_WALL_S]->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, (*maps)->texture_s, \
			&texture_size_x, &texture_size_y);
	((*maps)->textures)[TEXTURE_WALL_S]->data = \
		(int *)mlx_get_data_addr(((*maps)->textures)[TEXTURE_WALL_S]->img_ptr, \
		&(((*maps)->textures)[TEXTURE_WALL_S]->bpp), \
		&(((*maps)->textures)[TEXTURE_WALL_S]->size_l), \
		&(((*maps)->textures)[TEXTURE_WALL_S]->endian));
}

static void	load_wall_w(t_maps **maps, int texture_size_x, int texture_size_y)
{
	((*maps)->textures)[TEXTURE_WALL_W]->img_ptr = \
		mlx_xpm_file_to_image((*maps)->mlx, (*maps)->texture_w, \
			&texture_size_x, &texture_size_y);
	((*maps)->textures)[TEXTURE_WALL_W]->data = \
		(int *)mlx_get_data_addr(((*maps)->textures)[TEXTURE_WALL_W]->img_ptr, \
		&(((*maps)->textures)[TEXTURE_WALL_W]->bpp), \
		&(((*maps)->textures)[TEXTURE_WALL_W]->size_l), \
		&(((*maps)->textures)[TEXTURE_WALL_W]->endian));
}

void	load_textures(t_maps **maps)
{
	int	texture_size_x;
	int	texture_size_y;

	texture_size_x = TEXTURE_SIZE_X;
	texture_size_y = TEXTURE_SIZE_Y;
	load_wall_n(maps, texture_size_x, texture_size_y);
	load_wall_e(maps, texture_size_x, texture_size_y);
	load_wall_s(maps, texture_size_x, texture_size_y);
	load_wall_w(maps, texture_size_x, texture_size_y);
}
