/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 11:58:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	hit_wall(t_maps *maps, t_ray *ray)
{
	t_tiles	*tileptr;

	tileptr = maps->tiles;
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray->pointing_position[0] && tileptr->y_pos == \
							ray->pointing_position[1] && \
							(tileptr->type == '1' || tileptr->type == '2' || \
							tileptr->type == '3' || tileptr->type == '4' || \
							tileptr->type == '5' || tileptr->type == '6'))
			return (1);
		tileptr = tileptr->next;
	}
	if (fabs(ray->pointing_position[0] - ray->actual_position[0]) + \
		fabs(ray->pointing_position[1] - ray->actual_position[1]) > 50)
		return (1);
	return (0);
}

static void	get_perpendicular_distances_first_wall(t_maps *maps, t_ray *ray)
{
	int	hit;

	hit = 0;
	ray->side = 0;
	while (hit == 0)
	{
		if (ray->distance_next_position[0] < ray->distance_next_position[1])
		{
			ray->distance_next_position[0] += ray->delta_distance[0];
			ray->pointing_position[0] += ray->next_step_position[0];
			ray->side = 0;
		}
		else
		{
			ray->distance_next_position[1] += ray->delta_distance[1];
			ray->pointing_position[1] += ray->next_step_position[1];
			ray->side = 1;
		}
		if (hit_wall(maps, ray) != 0)
			hit = 1;
	}
	ray->perpendicular_distance = ray->distance_next_position[ray->side] - \
												ray->delta_distance[ray->side];
}

static void	get_y_needed_value(t_maps *map, t_ray *ray)
{
	ray->height = (int)(WINDOWS_SIZE_Y / ray->perpendicular_distance * 1);
	ray->start = -ray->height / 2 + WINDOWS_SIZE_Y / 2 + map->pitch;
	ray->end = ray->height / 2 + WINDOWS_SIZE_Y / 2 + map->pitch;
	if (ray->start < 0)
		ray->start = 0;
	if (ray->end >= WINDOWS_SIZE_Y)
		ray->end = WINDOWS_SIZE_Y;
}

static int	get_right_texture(t_maps *maps, t_ray *ray, t_texture *text)
{
	t_tiles	*tiles_ptr;

	tiles_ptr = maps->tiles;
	text->number_texture = 1;
	while (tiles_ptr != NULL)
	{
		if (tiles_ptr->x_pos == ray->pointing_position[0] && \
			tiles_ptr->y_pos == ray->pointing_position[1])
			text->number_texture = tiles_ptr->type - 48;
		tiles_ptr = tiles_ptr->next;
	}
	if (text->number_texture <= 0 || text->number_texture > 6)
		return (0);
	return (1);
}

void	pre_calc_raycasting_2(t_maps *maps, t_ray *ray, t_texture *text)
{
	get_perpendicular_distances_first_wall(maps, ray);
	if (get_right_texture(maps, ray, text) == 0)
	{
		ray->height = 0;
		ray->start = WINDOWS_SIZE_Y / 2 + maps->pitch;
		ray->end = WINDOWS_SIZE_Y / 2 + maps->pitch;
	}
	else
		get_y_needed_value(maps, ray);
}
