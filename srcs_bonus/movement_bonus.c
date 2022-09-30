/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/29 19:00:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	move_on_map(t_maps **maps, int keycode, double range)
{
	double	anglemvm;
	double	x;
	double	y;

	anglemvm = 0;
	if (keycode == 'w')
		anglemvm = (*maps)->angle_h + 0;
	if (keycode == 'd')
		anglemvm = (*maps)->angle_h + 0.5;
	if (keycode == 's')
		anglemvm = (*maps)->angle_h + 1;
	if (keycode == 'a')
		anglemvm = (*maps)->angle_h + 1.5;
	if (anglemvm > 2)
		anglemvm = anglemvm - 2;
	x = (*maps)->x_pos + range * sin(anglemvm * M_PI);
	y = (*maps)->y_pos + range * -cos(anglemvm * M_PI);
	if (is_out_of_wall(maps, x, y) == 1)
		return ;
	(*maps)->x_pos = x;
	(*maps)->y_pos = y;
}

void	change_pitch(int *pitch, int value)
{
	*pitch += value;
	if (*pitch > WINDOWS_SIZE_Y / 2)
		*pitch = WINDOWS_SIZE_Y / 2;
	if (*pitch < -WINDOWS_SIZE_Y / 2)
		*pitch = -WINDOWS_SIZE_Y / 2;
}

void	rotate(double *angle, double value)
{
	*angle += (value);
	if (*angle > 2)
		*angle = *angle - 2;
	else if (*angle < 0)
		*angle = 2 + *angle;
}

void	move(t_maps **maps)
{
	if ((*maps)->key_pressed[KEY_W] == 1)
		move_on_map(maps, 'w', KEY_MOVE * (*maps)->movement_factor / 2);
	if ((*maps)->key_pressed[KEY_A] == 1)
		move_on_map(maps, 'a', KEY_MOVE * (*maps)->movement_factor / 2);
	if ((*maps)->key_pressed[KEY_S] == 1)
		move_on_map(maps, 's', KEY_MOVE * (*maps)->movement_factor / 2);
	if ((*maps)->key_pressed[KEY_D] == 1)
		move_on_map(maps, 'd', KEY_MOVE * (*maps)->movement_factor / 2);
	if ((*maps)->key_pressed[KEY_UP] == 1)
		change_pitch(&((*maps)->pitch), -KEY_PITCH * (*maps)->movement_factor);
	if ((*maps)->key_pressed[KEY_LEFT] == 1)
		rotate(&((*maps)->angle_h), -KEY_ANGLE * (*maps)->movement_factor / 2);
	if ((*maps)->key_pressed[KEY_DOWN] == 1)
		change_pitch(&((*maps)->pitch), KEY_PITCH * (*maps)->movement_factor);
	if ((*maps)->key_pressed[KEY_RIGHT] == 1)
		rotate(&((*maps)->angle_h), KEY_ANGLE * (*maps)->movement_factor / 2);
}
