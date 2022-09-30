/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/29 19:38:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_scene(t_maps **maps)
{
	(*maps)->img->img_ptr = mlx_new_image((*maps)->mlx, \
										WINDOWS_SIZE_X, WINDOWS_SIZE_Y);
	(*maps)->img->data = (int *)mlx_get_data_addr(\
		(*maps)->img->img_ptr, &((*maps)->img->bpp), \
		&((*maps)->img->size_l), &((*maps)->img->endian));
	draw_pov(maps);
	draw_entities(maps);
	draw_minimap(maps);
	mlx_put_image_to_window((*maps)->mlx, (*maps)->mlx_win, \
						(*maps)->img->img_ptr, 0, 0);
	mlx_destroy_image((*maps)->mlx, (*maps)->img->img_ptr);
	(*maps)->img->img_ptr = NULL;
}
