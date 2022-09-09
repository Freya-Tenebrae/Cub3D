/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/29 18:04:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	hit_wall(t_maps *maps, t_ray *ray)
{
	t_tiles	*tileptr;

	tileptr = maps->tiles;
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray->pointing_position[0] && tileptr->y_pos == \
							ray->pointing_position[1] && tileptr->type == '1')
			return (1);
		tileptr = tileptr->next;
	}
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

static void	get_right_texture(t_ray *ray, t_texture *text)
{
	if (ray->side == 0)
	{
		if (ray->ray_direction[0] < 0)
			text->number_texture = TEXTURE_WALL_W;
		else
			text->number_texture = TEXTURE_WALL_E;
	}
	else
	{
		if (ray->ray_direction[1] < 0)
			text->number_texture = TEXTURE_WALL_S;
		else
			text->number_texture = TEXTURE_WALL_N;
	}
}

void	pre_calc_raycasting_2(t_maps *maps, t_ray *ray, t_texture *text)
{
	get_perpendicular_distances_first_wall(maps, ray);
	get_y_needed_value(maps, ray);
	get_right_texture(ray, text);
}
