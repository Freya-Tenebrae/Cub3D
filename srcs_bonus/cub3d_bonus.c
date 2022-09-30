/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/29 18:59:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	loop(t_maps **maps)
{
	update_frame(maps);
	get_movement_factor(maps);
	move(maps);
	draw_scene(maps);
	return (0);
}

static void	parsing(int argc, const char **argv, t_maps **maps)
{
	if (argc != 2)
		error("incorrect numbers of arguments", maps);
	get_map(maps, argv[1]);
	check_map_validity(maps);
	check_validity_textures(maps);
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;

	maps = init_maps();
	parsing(argc, argv, &maps);
	maps->mlx = mlx_init();
	if (!(maps->mlx))
		error("initiatisation of mlx failed", &maps);
	maps->mlx_win = mlx_new_window(maps->mlx, WINDOWS_SIZE_X, \
													WINDOWS_SIZE_Y, "cub3d");
	if (!(maps->mlx_win))
		error("initiatisation of mlx windows failed", &maps);
	load_textures(&maps);
	event_hook(&maps);
	draw_scene(&maps);
	mlx_loop_hook(maps->mlx, loop, &maps);
	mlx_loop(maps->mlx);
	error("mlx_loop stoped working unexpectedly", &maps);
	return (0);
}
