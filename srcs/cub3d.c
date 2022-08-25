/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/24 19:14:05 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
in next function
	usleep(80000);
	if (ft_update_frame(maps) != 0)
	{
		ft_free_maps(maps);
		ft_error("malloc error");
	}
	if (ft_draw_scene(maps) != 0)
	{
		ft_free_maps(maps);
		ft_error("drawing error");
	}
*/

static int	ft_render_next_frame(t_maps **maps)
{
	draw_scene(maps);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;

	maps = NULL;
	if (argc != 2)
		error("incorrect numbers of arguments", &maps);
	maps = init_maps();
	get_map(&maps, argv[1]);
	check_map_validity(&maps);
	check_color_value(&maps);
	affmap(maps);
	maps->mlx = mlx_init();
	maps->mlx_win = mlx_new_window(maps->mlx, WINDOWS_SIZE_X, \
													WINDOWS_SIZE_Y, "cub3d");
	load_textures(&maps);
	event_hook(&maps);
	draw_scene(&maps);
	mlx_loop_hook(maps->mlx, ft_render_next_frame, &maps);
	mlx_loop(maps->mlx);
	error("mlx_loop stoped working unexpectedly", &maps);
	return (0);
}
