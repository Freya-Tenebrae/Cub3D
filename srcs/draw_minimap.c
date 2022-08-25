/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:34:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/25 19:27:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_wall_minimap(t_maps **maps, t_tiles *tiles_ptr)
{
	int		count_x;
	int		count_y;
	int		diff_pos_x;
	int		diff_pos_y;

	diff_pos_x = (tiles_ptr->x_pos - (int)(*maps)->x_pos) * 10;
	diff_pos_y = (tiles_ptr->y_pos - (int)(*maps)->y_pos) * 10;
	count_y = -1;
	while (++count_y < WINDOWS_SIZE_Y / 4)
	{
		count_x = -1;
		while (++count_x < WINDOWS_SIZE_X / 4)
		{
			if ((diff_pos_y + WINDOWS_SIZE_Y / 8 - 5 <= count_y) && \
				(diff_pos_y + WINDOWS_SIZE_Y / 8 + 5 > count_y) && \
				(diff_pos_x + WINDOWS_SIZE_X / 8 - 5 <= count_x) && \
				(diff_pos_x + WINDOWS_SIZE_X / 8 + 5 > count_x))
				(*maps)->img->data[count_y * WINDOWS_SIZE_X + \
					3 * WINDOWS_SIZE_X / 4 + count_x] = COLOR_WALL_MINIMAP;
		}
	}
}

static void	draw_player_minimap(t_maps **maps)
{
	int	count_x;
	int	count_y;
	int	val_x;
	int	val_y;

	count_y = WINDOWS_SIZE_Y / 8 - 10;
	val_y = -9;
	while (++count_y < WINDOWS_SIZE_Y / 8 + 9)
	{
		++val_y;
		count_x = WINDOWS_SIZE_X / 8 - 10;
		val_x = -9;
		while (++count_x < WINDOWS_SIZE_X / 8 + 9)
		{
			++val_x;
			if (val_y * (val_y - 1) + val_x * (val_x - 1) <= 4 * 4)
			{
				(*maps)->img->data[count_y * WINDOWS_SIZE_X + \
					3 * WINDOWS_SIZE_X / 4 + count_x] = COLOR_PLAYER_MINIMAP;
			}
		}
	}
}

void	draw_minimap(t_maps **maps)
{
	t_tiles	*tiles_ptr;

	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		if (tiles_ptr->type == '1')
			draw_wall_minimap(maps, tiles_ptr);
		tiles_ptr = tiles_ptr->next;
	}
	draw_player_minimap(maps);
}
