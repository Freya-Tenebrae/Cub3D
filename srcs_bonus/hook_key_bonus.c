/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/29 19:04:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
	if (keycode == ARROW_UP)
		(*maps)->key_pressed[KEY_UP] = 1;
	if (keycode == ARROW_LEFT)
		(*maps)->key_pressed[KEY_LEFT] = 1;
	if (keycode == ARROW_DOWN)
		(*maps)->key_pressed[KEY_DOWN] = 1;
	if (keycode == ARROW_RIGHT)
		(*maps)->key_pressed[KEY_RIGHT] = 1;
	if (keycode == 'e')
		action(maps);
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

void	event_hook_key(t_maps **maps)
{
	mlx_hook((*maps)->mlx_win, 2, 1L << 0, key_pressed_hook, maps);
	mlx_hook((*maps)->mlx_win, 3, 1L << 1, key_release_hook, maps);
}
