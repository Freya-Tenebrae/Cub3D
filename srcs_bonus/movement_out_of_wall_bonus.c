/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_out_of_wall_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:18:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	is_out_of_wall_opposite_value(t_maps **maps, double x, double y, \
																	int sign)
{
	t_tiles	*tiles_ptr;
	int		f_xpos;
	int		f_ypos;

	f_xpos = floor(x + (double)(-1 * sign * KEY_MOVE));
	f_ypos = floor(y + (double)(sign * KEY_MOVE));
	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		if (f_xpos == tiles_ptr->x_pos && f_ypos == tiles_ptr->y_pos && \
			((tiles_ptr->type >= '1' && tiles_ptr->type <= '6') || \
			(tiles_ptr->type >= 'A' && tiles_ptr->type <= 'D') || \
			(tiles_ptr->type >= 'F' && tiles_ptr->type <= 'H')))
		{
			if (f_xpos != tiles_ptr->x_pos && f_xpos != x)
				(*maps)->x_pos = x;
			if (f_ypos != tiles_ptr->y_pos && f_ypos != y)
				(*maps)->y_pos = y;
			return (1);
		}
		tiles_ptr = tiles_ptr->next;
	}
	return (0);
}

static int	is_out_of_wall_same_value(t_maps **maps, double x, double y, \
																int sign)
{
	t_tiles	*tiles_ptr;
	int		f_xpos;
	int		f_ypos;

	f_xpos = floor(x + (double)(sign * KEY_MOVE));
	f_ypos = floor(y + (double)(sign * KEY_MOVE));
	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		if (f_xpos == tiles_ptr->x_pos && f_ypos == tiles_ptr->y_pos && \
			((tiles_ptr->type >= '1' && tiles_ptr->type <= '6') || \
			(tiles_ptr->type >= 'A' && tiles_ptr->type <= 'D') || \
			(tiles_ptr->type >= 'F' && tiles_ptr->type <= 'H')))
		{
			if (f_xpos != tiles_ptr->x_pos && f_xpos != x)
				(*maps)->x_pos = x;
			if (f_ypos != tiles_ptr->y_pos && f_ypos != y)
				(*maps)->y_pos = y;
			return (1);
		}
		tiles_ptr = tiles_ptr->next;
	}
	return (0);
}

int	is_out_of_wall(t_maps **maps, double x, double y)
{
	if (is_out_of_wall_same_value(maps, x, y, 1) == 1)
		return (1);
	if (is_out_of_wall_same_value(maps, x, y, -1) == 1)
		return (1);
	if (is_out_of_wall_opposite_value(maps, x, y, 1) == 1)
		return (1);
	if (is_out_of_wall_opposite_value(maps, x, y, -1) == 1)
		return (1);
	return (0);
}
