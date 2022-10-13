/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:34:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/13 18:50:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_entitie_minimap(t_maps **maps, t_tiles *tiles_ptr)
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
					3 * WINDOWS_SIZE_X / 4 + count_x] = \
					get_value_with_transparency((*maps)->img->data[count_y \
					* WINDOWS_SIZE_X + 3 * WINDOWS_SIZE_X / 4 + count_x], \
					COLOR_ENTITIE_MINIMAP, 0.5);
		}
	}
}

static void	draw_door_minimap(t_maps **maps, t_tiles *tiles_ptr)
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
					3 * WINDOWS_SIZE_X / 4 + count_x] = \
					get_value_with_transparency((*maps)->img->data[count_y \
					* WINDOWS_SIZE_X + 3 * WINDOWS_SIZE_X / 4 + count_x], \
					COLOR_DOOR_MINIMAP, 0.5);
		}
	}
}

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
					3 * WINDOWS_SIZE_X / 4 + count_x] = \
					get_value_with_transparency((*maps)->img->data[count_y \
					* WINDOWS_SIZE_X + 3 * WINDOWS_SIZE_X / 4 + count_x], \
					COLOR_WALL_MINIMAP, 0.5);
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
					3 * WINDOWS_SIZE_X / 4 + count_x] = \
					get_value_with_transparency((*maps)->img->data[count_y \
					* WINDOWS_SIZE_X + 3 * WINDOWS_SIZE_X / 4 + count_x], \
					COLOR_PLAYER_MINIMAP, 0.5);
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
		if ((tiles_ptr->type == '1' || tiles_ptr->type == '2' || \
			tiles_ptr->type == '3' || tiles_ptr->type == '4' || \
			tiles_ptr->type == '5' || tiles_ptr->type == '6'))
			draw_wall_minimap(maps, tiles_ptr);
		else if ((tiles_ptr->type >= 'A' && tiles_ptr->type <= 'D') || \
			(tiles_ptr->type >= 'F' && tiles_ptr->type <= 'H'))
			draw_door_minimap(maps, tiles_ptr);
		else if ((tiles_ptr->type >= 'a' && tiles_ptr->type <= 'd') || \
			(tiles_ptr->type >= 'f' && tiles_ptr->type <= 'h'))
			draw_entitie_minimap(maps, tiles_ptr);
		tiles_ptr = tiles_ptr->next;
	}
	draw_player_minimap(maps);
}
