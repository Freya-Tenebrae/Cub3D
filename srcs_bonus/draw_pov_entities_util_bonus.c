/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_entities_util_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/30 17:29:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	get_relative_position_and_depth(t_maps *maps, t_entitie *entitie)
{
	double	inversion;
	double	tmp;

	entitie->pos_relative[0] = entitie->pos_absolute[0] - maps->x_pos;
	entitie->pos_relative[1] = entitie->pos_absolute[1] - maps->y_pos;
	inversion = 1.0 / (entitie->plane[0] * entitie->direction[1] - \
						entitie->plane[1] * entitie->direction[0]);
	entitie->depth = inversion * (-entitie->plane[1] * \
							entitie->pos_relative[0] + entitie->plane[0] * \
													entitie->pos_relative[1]);
	tmp = inversion * (entitie->direction[1] * entitie->pos_relative[0] - \
							entitie->direction[0] * entitie->pos_relative[1]);
	entitie->x_pos_on_screen = (int)((WINDOWS_SIZE_X / 2) * (1 + \
													tmp / entitie->depth));
}

static void	get_x_and_y_needed_value(t_maps *map, t_entitie *entitie)
{
	entitie->height_and_width = abs((int)(WINDOWS_SIZE_Y / entitie->depth));
	entitie->start[0] = -entitie->height_and_width / 2 + \
													entitie->x_pos_on_screen;
	entitie->end[0] = entitie->height_and_width / 2 + entitie->x_pos_on_screen;
	if (entitie->start[0] < 0)
		entitie->start[0] = 0;
	if (entitie->end[0] >= WINDOWS_SIZE_X)
		entitie->end[0] = WINDOWS_SIZE_X;
	entitie->start[1] = -entitie->height_and_width / 2 + WINDOWS_SIZE_Y / 2 + \
																	map->pitch;
	entitie->end[1] = entitie->height_and_width / 2 + WINDOWS_SIZE_Y / 2 + \
																	map->pitch;
	if (entitie->start[1] < 0)
		entitie->start[1] = 0;
	if (entitie->end[1] >= WINDOWS_SIZE_Y)
		entitie->end[1] = WINDOWS_SIZE_Y;
}

void	pre_calc_raycasting_entities(t_maps *maps, t_entitie *entitie)
{
	get_relative_position_and_depth(maps, entitie);
	get_x_and_y_needed_value(maps, entitie);
}
