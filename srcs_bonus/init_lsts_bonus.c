/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lsts_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/23 06:52:39 by cmaginot         ###   ########.fr       */
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

t_actor	*init_actor(t_maps **maps, char **l)
{
	t_actor	*actor;

	actor = malloc(sizeof(t_actor));
	if (!actor)
	{
		free(*l);
		error("malloc error", maps);
	}
	actor->type = '0';
	actor->x_pos = 0;
	actor->y_pos = 0;
	actor->time_down = 0;
	actor->direction = 1;
	actor->next = NULL;
	return (actor);
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
	int	i;

	i = -1;
	while (++i < N_KEY)
		(*maps)->key_pressed[i] = 0;
	i = -1;
	while (++i < N_DOOR)
		(*maps)->cristal_get[i] = 0;
	i = -1;
	while (++i < N_SPELL)
		(*maps)->spells[i] = 0;
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
	(*maps)->actor = NULL;
}

t_maps	*init_maps(void)
{
	int		i;
	t_maps	*maps;

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
	while (++i < WINDOWS_SIZE_X)
		maps->z_buffer[i] = 0.0;
	i = -1;
	fill_maps_with_null(&maps);
	maps->status_game = WAITING;
	(*maps).life = N_LIFE;
	maps->n_maps = 0;
	return (maps);
}
