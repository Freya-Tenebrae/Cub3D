/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/25 20:24:07 by cmaginot         ###   ########.fr       */
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

static int	loop(t_maps **maps)
{
	if ((*maps)->key_pressed[KEY_W] == 1)
		move(maps, 'w', KEY_MOVE);
	if ((*maps)->key_pressed[KEY_A] == 1)
		move(maps, 'a', KEY_MOVE);
	if ((*maps)->key_pressed[KEY_S] == 1)
		move(maps, 's', KEY_MOVE);
	if ((*maps)->key_pressed[KEY_D] == 1)
		move(maps, 'd', KEY_MOVE);
	if ((*maps)->key_pressed[KEY_E] == 1)
		aff_position(*maps);
	if ((*maps)->key_pressed[KEY_UP] == 1)
		change_pitch(&((*maps)->pitch), -KEY_PITCH);
	if ((*maps)->key_pressed[KEY_LEFT] == 1)
		rotate(&((*maps)->angle_h), -KEY_ANGLE);
	if ((*maps)->key_pressed[KEY_DOWN] == 1)
		change_pitch(&((*maps)->pitch), KEY_PITCH);
	if ((*maps)->key_pressed[KEY_RIGHT] == 1)
		rotate(&((*maps)->angle_h), KEY_ANGLE);
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
	mlx_loop_hook(maps->mlx, loop, &maps);
	mlx_loop(maps->mlx);
	error("mlx_loop stoped working unexpectedly", &maps);
	return (0);
}
