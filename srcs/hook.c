/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/25 21:13:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_pressed_hook(int keycode, t_maps **maps)
{
	if (keycode == ESC_KEY)
		success(maps);
	if (keycode == 'w')
		(*maps)->key_pressed[KEY_W] = 1;
	if (keycode == 'a')
		(*maps)->key_pressed[KEY_A] = 1;
	if (keycode == 's')
		(*maps)->key_pressed[KEY_S] = 1;
	if (keycode == 'd')
		(*maps)->key_pressed[KEY_D] = 1;
	if (keycode == 'e')
		(*maps)->key_pressed[KEY_E] = 1;
	if (keycode == ARROW_UP)
		(*maps)->key_pressed[KEY_UP] = 1;
	if (keycode == ARROW_LEFT)
		(*maps)->key_pressed[KEY_LEFT] = 1;
	if (keycode == ARROW_DOWN)
		(*maps)->key_pressed[KEY_DOWN] = 1;
	if (keycode == ARROW_RIGHT)
		(*maps)->key_pressed[KEY_RIGHT] = 1;
	return (0);
}

static int	key_release_hook(int keycode, t_maps **maps)
{
	if (keycode == 'w')
		(*maps)->key_pressed[KEY_W] = 0;
	if (keycode == 'a')
		(*maps)->key_pressed[KEY_A] = 0;
	if (keycode == 's')
		(*maps)->key_pressed[KEY_S] = 0;
	if (keycode == 'd')
		(*maps)->key_pressed[KEY_D] = 0;
	if (keycode == 'e')
		(*maps)->key_pressed[KEY_E] = 0;
	if (keycode == ARROW_UP)
		(*maps)->key_pressed[KEY_UP] = 0;
	if (keycode == ARROW_LEFT)
		(*maps)->key_pressed[KEY_LEFT] = 0;
	if (keycode == ARROW_DOWN)
		(*maps)->key_pressed[KEY_DOWN] = 0;
	if (keycode == ARROW_RIGHT)
		(*maps)->key_pressed[KEY_RIGHT] = 0;
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
		rotate(&((*maps)->angle_h), MOUSE_ANGLE * (x - WINDOWS_SIZE_X / 2));
	if (x > WINDOWS_SIZE_X / 2)
		rotate(&((*maps)->angle_h), MOUSE_ANGLE * (x - WINDOWS_SIZE_X / 2));
	if (y < WINDOWS_SIZE_Y / 2)
		change_pitch(&((*maps)->pitch), MOUSE_PITCH * -(y - WINDOWS_SIZE_Y / \
																		2));
	if (y > WINDOWS_SIZE_Y / 2)
		change_pitch(&((*maps)->pitch), MOUSE_PITCH * -(y - WINDOWS_SIZE_Y / \
																		2));
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
	mlx_hook((*maps)->mlx_win, 2, 1L << 0, key_pressed_hook, maps);
	mlx_hook((*maps)->mlx_win, 3, 1L << 1, key_release_hook, maps);
	mlx_hook((*maps)->mlx_win, 4, 1L << 2, mouse_hook, maps);
	mlx_hook((*maps)->mlx_win, 6, 1L << 6, mouvement_mouse_hook, maps);
	mlx_hook((*maps)->mlx_win, 17, 1L << 17, close_hook, maps);
}
