/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/29 17:46:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_scene(t_maps **maps)
{
	(*maps)->img->img_ptr = mlx_new_image((*maps)->mlx, \
										WINDOWS_SIZE_X, WINDOWS_SIZE_Y);
	(*maps)->img->data = (int *)mlx_get_data_addr(\
		(*maps)->img->img_ptr, &((*maps)->img->bpp), \
		&((*maps)->img->size_l), &((*maps)->img->endian));
	draw_pov(maps);
	draw_minimap(maps);
	mlx_put_image_to_window((*maps)->mlx, (*maps)->mlx_win, \
						(*maps)->img->img_ptr, 0, 0);
	mlx_destroy_image((*maps)->mlx, (*maps)->img->img_ptr);
	(*maps)->img->img_ptr = NULL;
}
