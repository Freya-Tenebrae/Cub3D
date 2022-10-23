/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ath_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:34:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/23 07:38:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_key_2(t_maps **maps, int i, int x, int y)
{
	int	color;

	color = (*maps)->textures_entities->data[(i + 4) * 64 * 64 * \
		N_FRAME + x + y * 64 * N_FRAME];
	if (color != 65280)
	{
		if ((*maps)->cristal_get[i] == 1)
			(*maps)->img->data[i * 64 + x + y * WINDOWS_SIZE_X] = color;
		else
		{
			(*maps)->img->data[i * 64 + x + y * WINDOWS_SIZE_X] = \
			get_value_with_transparency((*maps)->img->data[i * 64 + \
				x + y * WINDOWS_SIZE_X], 0, 0.75);
		}
	}
}

void	draw_key(t_maps **maps, int i)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			draw_key_2(maps, i, x, y);
		}
	}
}
