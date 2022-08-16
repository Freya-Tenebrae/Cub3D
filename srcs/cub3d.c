/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 17:21:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_hook(int keycode, t_maps **maps)
{
	if (keycode == ESC_KEY)
		success(maps);
	else if ((keycode == 'w' || keycode == 'a' || keycode == 's' || \
			keycode == 'd') && (*maps)->status_game == 0)
	{
		ft_putchar('.'); // todelete
	// 	if (ft_move(maps, keycode) == -3)
	// 		error("malloc error", &maps);
	// 	ft_putstr_fd("Movements : ", 1);
	// 	ft_putnbr_fd((*maps)->movements, 1);
	// 	ft_putstr_fd(".\n", 1);
	}
	// if (ft_draw_scene(maps) != 0)
	// 	error("drawing error", &maps);
	return (0);
}

static int	close_hook(t_maps **maps)
{
	success(maps);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;

	maps = NULL;
	if (argc != 2)
		error("incorrect numbers of arguments", &maps);
	maps = init_maps();
	if (!maps)
		error("malloc error", &maps);
	get_map(&maps, argv[1]);
	check_map_validity(&maps);
	affmap(maps);
	maps->mlx = mlx_init();
	maps->mlx_win = mlx_new_window(maps->mlx, WINDOWS_SIZE_X, \
									WINDOWS_SIZE_Y, "cub3d");
	// if (draw_scene(&maps) != 0)
	// 	error("drawing error", &maps);
	mlx_key_hook(maps->mlx_win, key_hook, &maps);
	mlx_hook(maps->mlx_win, 17, 1L << 17, close_hook, &maps);
	mlx_loop(maps->mlx);
	error("mlx_loop stoped working unexpectedly", &maps);
	return (0);
}
