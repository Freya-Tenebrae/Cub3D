/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lsts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 07:54:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_tiles	*init_tile(t_maps **maps, char **l)
{
	t_tiles	*tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
	{
		free(*l);
		error("malloc error", maps);
	}
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
	(*maps)->x_lenght = 0;
	(*maps)->y_lenght = 0;
	(*maps)->x_pos = 0;
	(*maps)->y_pos = 0;
	(*maps)->angle_h = 0;
	(*maps)->movement_factor = 0;
	(*maps)->pitch = 0;
	(*maps)->mlx = NULL;
	(*maps)->mlx_win = NULL;
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
	maps->textures_entities = init_img();
	if (!maps->textures_entities)
		error("malloc error", &maps);
	maps->textures_wall_floor = init_img();
	if (!maps->textures_wall_floor)
		error("malloc error", &maps);
	i = -1;
	while (++i < N_KEY)
		maps->key_pressed[i] = 0;
	fill_maps_with_null(&maps);
	return (maps);
}
