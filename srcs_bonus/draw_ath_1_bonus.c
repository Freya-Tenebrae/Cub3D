/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ath_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:34:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:19:08 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_spell_2(t_maps **maps, int i, int x, int y)
{
	int	color;

	color = (*maps)->textures_entities->data[(2 + i % 2) * 64 * 64 * \
		N_FRAME + x + y * 64 * N_FRAME];
	if (color != 65280)
	{
		if ((*maps)->spells[i] == 0)
		{
			(*maps)->img->data[i * 64 + 64 * WINDOWS_SIZE_X + x + y * \
			WINDOWS_SIZE_X] = color;
		}
		else
		{
			(*maps)->img->data[i * 64 + 64 * WINDOWS_SIZE_X + x + y * \
				WINDOWS_SIZE_X] = \
				get_value_with_transparency((*maps)->img->data[i * 64 + 64 * \
				WINDOWS_SIZE_X + x + y * WINDOWS_SIZE_X], 0, 0.75);
		}
	}
}

static void	draw_spell(t_maps **maps, int i)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			draw_spell_2(maps, i, x, y);
		}
	}
}

static void	draw_life_2(t_maps **maps, int i, int x, int y)
{
	int	color;

	color = (*maps)->textures_entities->data[11 * 64 * 64 * \
		N_FRAME + x + y * 64 * N_FRAME];
	if (color != 65280)
	{
		if ((*maps)->life > i)
			(*maps)->img->data[i * 64 + 128 * WINDOWS_SIZE_X + x + y * \
				WINDOWS_SIZE_X] = color;
		else
		{
			(*maps)->img->data[i * 64 + 128 * WINDOWS_SIZE_X + x + y * \
				WINDOWS_SIZE_X] = \
			get_value_with_transparency((*maps)->img->data[i * 64 + 128 * \
				WINDOWS_SIZE_X + x + y * WINDOWS_SIZE_X], 0, 0.75);
		}
	}
}

static void	draw_life(t_maps **maps, int i)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			draw_life_2(maps, i, x, y);
		}
	}
}

void	draw_ath(t_maps **maps)
{
	int	i;

	i = -1;
	while (++i < N_LIFE)
		draw_life(maps, i);
	i = -1;
	while (++i < N_SPELL)
		draw_spell(maps, i);
	i = -1;
	while (++i < N_DOOR)
		draw_key(maps, i);
}
