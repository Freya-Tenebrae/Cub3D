/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/01 20:37:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	event_hook_mouse(t_maps **maps)
{
	mlx_mouse_move((*maps)->mlx, (*maps)->mlx_win, WINDOWS_SIZE_X / 2, \
															WINDOWS_SIZE_Y / 2);
	mlx_hook((*maps)->mlx_win, 4, 1L << 2, mouse_hook, maps);
	mlx_hook((*maps)->mlx_win, 6, 1L << 6, mouvement_mouse_hook, maps);
}
