/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lsts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/05 13:00:38 by cmaginot         ###   ########.fr       */
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

static void	free_img(t_maps **maps, t_myimg **img)
{
	if (img != NULL && *img != NULL)
	{
		if ((*img)->img_ptr != NULL)
			mlx_destroy_image((*maps)->mlx, (*img)->img_ptr);
		free(*img);
	}
}

static void	free_textures(t_maps **maps)
{
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
}

void	free_maps(t_maps **maps)
{
	int		i;

	i = -1;
	if (maps != NULL && *maps != NULL)
	{
		free_tiles(&((*maps)->tiles));
		free_textures(maps);
		while (++i < N_TEXTURE)
			if (((*maps)->textures)[i] != NULL)
				free_img(maps, &(((*maps)->textures)[i]));
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
