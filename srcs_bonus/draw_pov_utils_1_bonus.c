/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_utils_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:19:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	get_ray_direction(t_maps *maps, t_ray *ray, int count_x)
{
	double	direction[2];
	double	plane[2];

	direction[0] = sin(maps->angle_h * M_PI);
	direction[1] = -cos(maps->angle_h * M_PI);
	plane[0] = sin((maps->angle_h + 0.5) * M_PI);
	plane[1] = -cos((maps->angle_h + 0.5) * M_PI);
	ray->ray_direction[0] = direction[0] + plane[0] * \
		(2 * count_x / (double)WINDOWS_SIZE_X - 1);
	ray->ray_direction[1] = direction[1] + plane[1] * \
		(2 * count_x / (double)WINDOWS_SIZE_X - 1);
}

static void	get_delta_distance(t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (ray->ray_direction[i] == 0)
				(ray->delta_distance)[i] = 1000000;
		else if (ray->ray_direction[i] > 0)
			(ray->delta_distance)[i] = 1 / ray->ray_direction[i];
		else
			(ray->delta_distance)[i] = -1 / ray->ray_direction[i];
	}
}

static void	get_position(t_maps *maps, t_ray *ray)
{
	ray->actual_position[0] = maps->x_pos;
	ray->actual_position[1] = maps->y_pos;
	ray->pointing_position[0] = (int)maps->x_pos;
	ray->pointing_position[1] = (int)maps->y_pos;
}

static void	get_direction(t_ray *ray)
{
	if (ray->ray_direction[0] < 0)
	{
		ray->next_step_position[0] = -1;
		ray->distance_next_position[0] = ((double)ray->actual_position[0] - \
			ray->pointing_position[0]) * ray->delta_distance[0];
	}
	else
	{
		ray->next_step_position[0] = 1;
		ray->distance_next_position[0] = (ray->pointing_position[0] + 1.0 - \
			(double)ray->actual_position[0]) * ray->delta_distance[0];
	}
	if (ray->ray_direction[1] < 0)
	{
		ray->next_step_position[1] = -1;
		ray->distance_next_position[1] = ((double)ray->actual_position[1] - \
			ray->pointing_position[1]) * ray->delta_distance[1];
	}
	else
	{
		ray->next_step_position[1] = 1;
		ray->distance_next_position[1] = (ray->pointing_position[1] + 1.0 - \
			(double)ray->actual_position[1]) * ray->delta_distance[1];
	}
}

void	pre_calc_raycasting_1(t_maps *maps, t_ray *ray, int count_x)
{
	get_ray_direction(maps, ray, count_x);
	get_delta_distance(ray);
	get_position(maps, ray);
	get_direction(ray);
}
