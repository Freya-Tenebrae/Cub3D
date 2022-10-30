/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lsts_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:18:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	free_tiles(t_tiles **tiles)
{
	t_tiles	*tilesnext;

	if (tiles != NULL)
	{
		while (*tiles != NULL)
		{
			tilesnext = (*tiles)->next;
			free(*tiles);
			*tiles = tilesnext;
		}
	}
}

static void	free_actor(t_actor **actor)
{
	t_actor	*actornext;

	if (actor != NULL)
	{
		while (*actor != NULL)
		{
			actornext = (*actor)->next;
			free(*actor);
			*actor = actornext;
		}
	}
}

static void	free_img(t_maps **maps, t_myimg **img)
{
	if (img != NULL && *img != NULL)
	{
		if ((*img)->img_ptr != NULL)
			mlx_destroy_image((*maps)->mlx, (*img)->img_ptr);
		free(*img);
	}
}

void	free_for_next_map(t_maps **maps)
{
	int		i;

	i = -1;
	if (maps != NULL && *maps != NULL)
	{
		free_tiles(&((*maps)->tiles));
		free_actor(&((*maps)->actor));
	}
	i = -1;
	while (++i < N_KEY)
		(*maps)->key_pressed[i] = 0;
	i = -1;
	while (++i < N_DOOR)
		(*maps)->cristal_get[i] = 0;
	(*maps)->x_lenght = 0;
	(*maps)->y_lenght = 0;
	(*maps)->x_pos = 0;
	(*maps)->y_pos = 0;
	(*maps)->angle_h = 0;
	(*maps)->movement_factor = 0;
	(*maps)->pitch = 0;
	(*maps)->n_frame = 0;
	(*maps)->tiles = NULL;
	(*maps)->actor = NULL;
}

void	free_maps(t_maps **maps)
{
	int		i;

	i = -1;
	if (maps != NULL && *maps != NULL)
	{
		free_tiles(&((*maps)->tiles));
		free_actor(&((*maps)->actor));
		if ((*maps)->textures_entities != NULL)
			free_img(maps, &((*maps)->textures_entities));
		if ((*maps)->textures_wall_floor != NULL)
			free_img(maps, &((*maps)->textures_wall_floor));
		free_img(maps, &((*maps)->img));
		if ((*maps)->mlx != NULL)
		{
			if ((*maps)->mlx_win != NULL)
				mlx_destroy_window((*maps)->mlx, (*maps)->mlx_win);
			mlx_destroy_display((*maps)->mlx);
			free((*maps)->mlx);
		}
		free((*maps));
	}
}
