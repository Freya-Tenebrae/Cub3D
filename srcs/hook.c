/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/24 21:34:05 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_hook(int keycode, t_maps **maps)
{
	if (keycode == ESC_KEY)
		success(maps);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move(maps, keycode, KEY_MOVE);
	if (keycode == 'e')
		aff_position(*maps);
	if (keycode == ARROW_LEFT)
		rotate(&((*maps)->angle_h), -1, KEY_ANGLE);
	if (keycode == ARROW_RIGHT)
		rotate(&((*maps)->angle_h), 1, KEY_ANGLE);
	if (keycode == ARROW_UP)
		change_pitch(&((*maps)->pitch), -KEY_PITCH);
	if (keycode == ARROW_DOWN)
		change_pitch(&((*maps)->pitch), KEY_PITCH);
	return (0);
}

static int	mouse_hook(int keycode, int x, int y, t_maps **maps)
{
	(void)x;
	(void)y;
	(void)maps;
	if (keycode == 1)
		ft_putstr("spell : cat transformation\n");
	return (0);
}

static int	mouvement_mouse_hook(int x, int y, t_maps **maps)
{
	if (x < WINDOWS_SIZE_X / 2)
		rotate(&((*maps)->angle_h), -1, MOUSE_ANGLE);
	if (x > WINDOWS_SIZE_X / 2)
		rotate(&((*maps)->angle_h), 1, MOUSE_ANGLE);
	if (y < WINDOWS_SIZE_Y / 2)
		change_pitch(&((*maps)->pitch), MOUSE_PITCH);
	if (y > WINDOWS_SIZE_Y / 2)
		change_pitch(&((*maps)->pitch), -MOUSE_PITCH);
	mlx_mouse_move((*maps)->mlx, (*maps)->mlx_win, WINDOWS_SIZE_X / 2, \
															WINDOWS_SIZE_Y / 2);
	return (0);
}

static int	close_hook(t_maps **maps)
{
	success(maps);
	return (0);
}

void	event_hook(t_maps **maps)
{
	mlx_mouse_move((*maps)->mlx, (*maps)->mlx_win, WINDOWS_SIZE_X / 2, \
															WINDOWS_SIZE_Y / 2);
	mlx_hook((*maps)->mlx_win, 2, 1L << 0, key_hook, maps);
	mlx_hook((*maps)->mlx_win, 4, 1L << 2, mouse_hook, maps);
	mlx_hook((*maps)->mlx_win, 6, 1L << 6, mouvement_mouse_hook, maps);
	mlx_hook((*maps)->mlx_win, 17, 1L << 17, close_hook, maps);
}
