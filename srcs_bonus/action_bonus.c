/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:41:24 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/29 18:59:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	hit_something(t_maps *maps, t_ray *ray)
{
	t_tiles	*tileptr;

	tileptr = maps->tiles;
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray->pointing_position[0] && tileptr->y_pos == \
						ray->pointing_position[1] && \
						((tileptr->type >= '1' && tileptr->type <= '6') || \
						(tileptr->type >= 'A' && tileptr->type <= 'D') || \
						(tileptr->type >= 'F' && tileptr->type <= 'H') || \
						(tileptr->type >= 'a' && tileptr->type <= 'd') || \
						(tileptr->type >= 'f' && tileptr->type <= 'h')))
			return (1);
		tileptr = tileptr->next;
	}
	if (fabs(ray->pointing_position[0] - ray->actual_position[0]) + \
		fabs(ray->pointing_position[1] - ray->actual_position[1]) > 2)
		return (1);
	return (0);
}

static void	get_distances_first_wall_door_or_entities(t_maps *maps, t_ray *ray)
{
	int	hit;

	hit = 0;
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
		if (hit_something(maps, ray) != 0)
			hit = 1;
	}
	ray->perpendicular_distance = ray->distance_next_position[ray->side] - \
												ray->delta_distance[ray->side];
}

static void	open_door(t_maps *maps, t_ray *ray, char action_on_what)
{
	t_tiles	*tileptr;

	tileptr = maps->tiles;
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray->pointing_position[0] && tileptr->y_pos == \
			ray->pointing_position[1])
		{
			if ((action_on_what >= 'A' && action_on_what <= 'D'))
			{
				if (maps->cristal_get[tileptr->type - 'A'] == 1)
					tileptr->type = '0';
			}
			else if ((action_on_what >= 'F' && action_on_what <= 'H'))
			{
				if (maps->cristal_get[tileptr->type - 'A' - '1'] == 1)
					tileptr->type = '0';
			}
			return ;
		}
		tileptr = tileptr->next;
	}
}

static void	take_pickup(t_maps *maps, t_ray *ray, char action_on_what)
{
	t_tiles	*tileptr;

	tileptr = maps->tiles;
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray->pointing_position[0] && tileptr->y_pos == \
			ray->pointing_position[1])
		{
			if ((action_on_what >= 'a' && action_on_what <= 'd'))
				maps->cristal_get[tileptr->type - 'a'] = 1;
			else if ((action_on_what >= 'f' && action_on_what <= 'h'))
				maps->cristal_get[tileptr->type - 'a' - '1'] = 1;
			tileptr->type = '0';
			return ;
		}
		tileptr = tileptr->next;
	}
}

void	action(t_maps **maps)
{
	t_ray		ray;
	char		action_on_what;
	t_tiles		*tileptr;

	pre_calc_raycasting_1(*maps, &ray, WINDOWS_SIZE_X / 2);
	get_distances_first_wall_door_or_entities(*maps, &ray);
	tileptr = (*maps)->tiles;
	action_on_what = '0';
	while (tileptr != NULL)
	{
		if (tileptr->x_pos == ray.pointing_position[0] && tileptr->y_pos == \
			ray.pointing_position[1])
			action_on_what = tileptr->type;
		tileptr = tileptr->next;
	}
	if ((action_on_what >= 'A' && action_on_what <= 'D') || \
		(action_on_what >= 'F' && action_on_what <= 'H'))
		open_door(*maps, &ray, action_on_what);
	if ((action_on_what >= 'a' && action_on_what <= 'd') || \
		(action_on_what >= 'f' && action_on_what <= 'h'))
		take_pickup(*maps, &ray, action_on_what);
	if (action_on_what == '6')
		success(maps);
}
