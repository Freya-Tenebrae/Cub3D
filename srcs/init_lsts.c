/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lsts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/24 20:01:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_tiles	*init_tile(void)
{
	t_tiles	*tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
		return (NULL);
	tiles->x_pos = 0;
	tiles->y_pos = 0;
	tiles->type = '0';
	tiles->next = NULL;
	return (tiles);
}

static t_myimg	*init_img(void)
{
	t_myimg		*img;

	img = malloc(sizeof(t_myimg));
	if (!img)
		return (NULL);
	img->img_ptr = NULL;
	img->data = NULL;
	img->size_l = 0;
	img->bpp = 0;
	img->endian = 0;
	return (img);
}

static void	fill_maps_with_null(t_maps **maps)
{
	(*maps)->texture_n = NULL;
	(*maps)->texture_s = NULL;
	(*maps)->texture_e = NULL;
	(*maps)->texture_w = NULL;
	(*maps)->color_f = NULL;
	(*maps)->color_c = NULL;
	(*maps)->code_color_f = 0;
	(*maps)->code_color_c = 0;
	(*maps)->x_lenght = 0;
	(*maps)->y_lenght = 0;
	(*maps)->x_pos = 0;
	(*maps)->y_pos = 0;
	(*maps)->angle_h = 0;
	(*maps)->pitch = 0;
	(*maps)->mlx = NULL;
	(*maps)->mlx_win = NULL;
	(*maps)->status_game = 0;
	(*maps)->n_frame = 0;
	(*maps)->tiles = NULL;
}

t_maps	*init_maps(void)
{
	int		i;
	t_maps	*maps;

	i = -1;
	maps = malloc(sizeof(t_maps));
	if (!maps)
		error("malloc error", NULL);
	maps->img = init_img();
	if (!maps->img)
		error("malloc error", &maps);
	while (++i < N_TEXTURE)
	{
		(maps->textures)[i] = init_img();
		if (!(maps->textures)[i])
			error("malloc error", &maps);
	}
	fill_maps_with_null(&maps);
	return (maps);
}
