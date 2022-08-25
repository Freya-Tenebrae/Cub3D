/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/25 20:21:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_and_manage_out_of_wall(t_maps **maps, double x, double y)
{
	t_tiles	*tileptr;
	int		f_xpos;
	int		f_ypos;

	f_xpos = floor(x);
	f_ypos = floor(y);
	tileptr = (*maps)->tiles;
	while (tileptr != NULL)
	{
		if (f_xpos == tileptr->x_pos && f_ypos == tileptr->y_pos && \
														tileptr->type == '1')
		{
			if (f_xpos != tileptr->x_pos && f_xpos != x)
				(*maps)->x_pos = x;
			if (f_ypos != tileptr->y_pos)
				(*maps)->y_pos = y;
			return ;
		}
		tileptr = tileptr->next;
	}
	(*maps)->x_pos = x;
	(*maps)->y_pos = y;
}

void	move(t_maps **maps, int keycode, double range)
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
	check_and_manage_out_of_wall(maps, x, y);
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
