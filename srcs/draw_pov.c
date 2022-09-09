/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/29 18:16:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_step_and_position_on_texture(t_maps *maps, t_ray *ray, \
	t_texture *text)
{
	if (ray->side == 0)
		text->position_x_on_wall = ray->actual_position[1] + \
			ray->perpendicular_distance * ray->ray_direction[1];
	else
		text->position_x_on_wall = ray->actual_position[0] + \
			ray->perpendicular_distance * ray->ray_direction[0];
	text->position_x_on_wall -= floor(text->position_x_on_wall);
	text->step = ((double)TEXTURE_SIZE_Y / (double)ray->height);
	text->pos_start_texture = text->step * (ray->start - WINDOWS_SIZE_Y / 2 + \
												ray->height / 2 - maps->pitch);
}

static void	draw_column(t_maps **maps, int count_x, t_ray *ray, t_texture *text)
{
	text->texture_position[0] = (int)(text->position_x_on_wall * \
														(double)TEXTURE_SIZE_X);
	if ((ray->side == 0 && ray->ray_direction[0] < 0) || \
		(ray->side == 1 && ray->ray_direction[1] > 0))
		text->texture_position[0] = TEXTURE_SIZE_X - \
												text->texture_position[0] - 1;
	while (ray->start < ray->end)
	{
		text->texture_position[1] = (int)text->pos_start_texture & \
														(TEXTURE_SIZE_Y - 1);
		text->pos_start_texture += text->step;
		(*maps)->img->data[ray->start * WINDOWS_SIZE_X + count_x] \
			= (((*maps)->textures)[text->number_texture]->data)[\
			text->texture_position[0] + text->texture_position[1] * \
			TEXTURE_SIZE_X];
		ray->start++;
	}
}

static void	draw_floor_and_ceiling(t_maps **maps, int count_x, t_ray *ray)
{
	int	count_y;

	count_y = -1;
	while (++count_y < ray->start)
		(*maps)->img->data[count_y * WINDOWS_SIZE_X + count_x] = \
														(*maps)->code_color_c;
	count_y = ray->end - 1;
	while (++count_y < WINDOWS_SIZE_Y)
		(*maps)->img->data[count_y * WINDOWS_SIZE_X + count_x] = \
														(*maps)->code_color_f;
}

void	draw_pov(t_maps **maps)
{
	int			count_x;
	t_ray		ray;
	t_texture	text;

	count_x = -1;
	while (++count_x < WINDOWS_SIZE_X)
	{
		pre_calc_raycasting_1(*maps, &ray, count_x);
		pre_calc_raycasting_2(*maps, &ray, &text);
		get_step_and_position_on_texture(*maps, &ray, &text);
		draw_floor_and_ceiling(maps, count_x, &ray);
		draw_column(maps, count_x, &ray, &text);
	}
}
