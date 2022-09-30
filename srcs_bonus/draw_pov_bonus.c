/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/30 17:15:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

static int	get_right_color_texture(t_maps **maps, t_texture *text)
{
	int	skip_to_right_texture;
	int	skip_to_right_lign;
	int	skip_to_right_frame;

	skip_to_right_texture = text->number_texture * N_FRAME * TEXTURE_SIZE_X * \
							TEXTURE_SIZE_Y;
	skip_to_right_lign = N_FRAME * TEXTURE_SIZE_X * text->texture_position[1];
	skip_to_right_frame = (*maps)->n_frame * TEXTURE_SIZE_X;
	return (((*maps)->textures_wall_floor->data)[skip_to_right_texture + \
		skip_to_right_lign + skip_to_right_frame + text->texture_position[0]]);
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
			= get_right_color_texture(maps, text);
		ray->start++;
	}
}

void	draw_pov(t_maps **maps)
{
	int			count_x;
	t_ray		ray;
	t_texture	text;

	draw_floor(maps);
	count_x = -1;
	while (++count_x < WINDOWS_SIZE_X)
	{
		pre_calc_raycasting_1(*maps, &ray, count_x);
		pre_calc_raycasting_2(*maps, &ray, &text);
		get_step_and_position_on_texture(*maps, &ray, &text);
		draw_column(maps, count_x, &ray, &text);
		(*maps)->z_buffer[count_x] = ray.perpendicular_distance;
	}
}
