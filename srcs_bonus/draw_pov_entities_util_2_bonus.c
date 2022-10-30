/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_entities_util_2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:19:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_number_text_and_step_actor(t_entitie *entitie, \
											t_texture_entitie *text, char type)
{
	if (type >= 'x' && type <= 'y')
		text->number_texture = type - 'x';
	else if (type >= 'X' && type <= 'Y')
		text->number_texture = type - 'X' + 2;
	else if (type >= 'a' && type <= 'd')
		text->number_texture = type - 'a' + 4;
	else if (type >= 'f' && type <= 'h')
		text->number_texture = type - 'f' + 8;
	text->step = (double)TEXTURE_SIZE_X / (double)entitie->height_and_width;
	text->pos_start_texture[0] = text->step * (entitie->start[0] - \
					entitie->x_pos_on_screen + entitie->height_and_width / 2);
}

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
