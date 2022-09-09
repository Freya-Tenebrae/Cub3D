/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:13:07 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 12:37:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	get_plane(t_maps **maps, t_floor *floor)
{
	floor->direction[0] = sin((*maps)->angle_h * M_PI);
	floor->direction[1] = -cos((*maps)->angle_h * M_PI);
	floor->plane[0] = sin(((*maps)->angle_h + 0.5) * M_PI);
	floor->plane[1] = -cos(((*maps)->angle_h + 0.5) * M_PI);
}

static void	get_ray_directions(t_maps **maps, t_floor *floor, int count_y)
{
	floor->rayDirectionRmv[0] = floor->direction[0] - floor->plane[0];
	floor->rayDirectionRmv[1] = floor->direction[1] - floor->plane[1];
	floor->rayDirectionAdd[0] = floor->direction[0] + floor->plane[0];
	floor->rayDirectionAdd[1] = floor->direction[1] + floor->plane[1];
	floor->verticalPositionFromCenter = count_y - WINDOWS_SIZE_Y / 2 - \
																(*maps)->pitch;
	floor->rowDistances = 0.5 * WINDOWS_SIZE_Y / \
											floor->verticalPositionFromCenter;
	floor->delta_distance[0] = floor->rowDistances * \
					(floor->rayDirectionAdd[0] - floor->rayDirectionRmv[0]) / \
																WINDOWS_SIZE_X;
	floor->delta_distance[1] = floor->rowDistances * \
					(floor->rayDirectionAdd[1] - floor->rayDirectionRmv[1]) / \
																WINDOWS_SIZE_X;
	floor->floor[0] = (*maps)->x_pos + floor->rowDistances * \
													floor->rayDirectionRmv[0];
	floor->floor[1] = (*maps)->y_pos + floor->rowDistances * \
													floor->rayDirectionRmv[1];
}

static void	print_floor(t_maps **maps, t_floor *floor, int count_x, int count_y)
{
	int	skip_to_right_lign;
	int	skip_to_right_frame;

	skip_to_right_lign = N_FRAME * TEXTURE_SIZE_X * floor->t[1];
	skip_to_right_frame = (*maps)->n_frame * TEXTURE_SIZE_X;
	(*maps)->img->data[count_y * WINDOWS_SIZE_X + count_x] = \
		((*maps)->textures_wall_floor->data)[skip_to_right_lign + \
		skip_to_right_frame + floor->t[0]];
}

static void	calc_pixel(t_floor *floor)
{
	floor->t[0] = (int)(TEXTURE_SIZE_X * (floor->floor[0] - \
			(int)floor->floor[0])) & (TEXTURE_SIZE_X - 1);
	floor->t[1] = (int)(TEXTURE_SIZE_X * (floor->floor[1] - \
			(int)floor->floor[1])) & (TEXTURE_SIZE_X - 1);
	floor->floor[0] += floor->delta_distance[0];
	floor->floor[1] += floor->delta_distance[1];
}

void	draw_floor(t_maps **maps)
{
	t_floor	floor;
	int		count_x;
	int		count_y;

	get_plane(maps, &floor);
	count_y = -1;
	while (++count_y < WINDOWS_SIZE_Y)
	{
		get_ray_directions(maps, &floor, count_y);
		count_x = -1;
		while (++count_x < WINDOWS_SIZE_X)
		{
			calc_pixel(&floor);
			if (count_y > WINDOWS_SIZE_Y / 2 + (*maps)->pitch)
			{
				print_floor(maps, &floor, count_x, count_y);
			}
			else
				(*maps)->img->data[count_y * WINDOWS_SIZE_X + count_x] = \
					COLOR_CEILING;
		}
	}
}
