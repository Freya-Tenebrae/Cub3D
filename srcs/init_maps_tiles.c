/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 16:45:09 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	push_tiles_back(t_maps **maps, t_tiles *tiles_to_push)
{
	t_tiles	*tilesptr;

	tilesptr = (*maps)->tiles;
	if ((*maps)->tiles == NULL)
		(*maps)->tiles = tiles_to_push;
	else
	{
		while (tilesptr->next != NULL)
			tilesptr = tilesptr->next;
		tilesptr->next = tiles_to_push;
	}
}

void	free_maps(t_maps **maps)
{
	if (maps != NULL && *maps != NULL)
	{
		free_tiles(&((*maps)->tiles));
		if ((*maps)->texture_n != NULL)
			free((*maps)->texture_n);
		if ((*maps)->texture_s != NULL)
			free((*maps)->texture_s);
		if ((*maps)->texture_e != NULL)
			free((*maps)->texture_e);
		if ((*maps)->texture_w != NULL)
			free((*maps)->texture_w);
		if ((*maps)->color_f != NULL)
			free((*maps)->color_f);
		if ((*maps)->color_c != NULL)
			free((*maps)->color_c);
		free(*maps);
	}
}

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

t_maps	*init_maps(void)
{
	t_maps	*maps;

	maps = malloc(sizeof(t_maps));
	if (!maps)
		return (NULL);
	maps->texture_n = NULL;
	maps->texture_s = NULL;
	maps->texture_e = NULL;
	maps->texture_w = NULL;
	maps->color_f = NULL;
	maps->color_c = NULL;
	maps->x_lenght = 0;
	maps->y_lenght = 0;
	maps->x_pos = 0;
	maps->y_pos = 0;
	maps->angle = 0;
	maps->mlx = NULL;
	maps->mlx_win = NULL;
	maps->status_game = 0;
	maps->n_frame = 0;
	maps->tiles = NULL;
	return (maps);
}
