/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tool_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:40:47 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/13 19:48:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

unsigned long	get_time(void)
{
	struct timeval	tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

void	update_frame(t_maps **maps)
{
	static unsigned long	time_start;
	unsigned long			time_act;

	if (!time_start)
		time_start = get_time();
	time_act = get_time();
	if (time_act - time_start >= 200)
	{
		if ((*maps)->n_frame == 7)
			(*maps)->n_frame = 0;
		else
			(*maps)->n_frame += 1;
		time_start = time_act;
	}
}

void	get_movement_factor(t_maps **maps)
{
	static unsigned long	time_start;
	unsigned long			time_act;

	if (!time_start)
		time_start = get_time();
	time_act = get_time();
	(*maps)->movement_factor = (time_act - time_start) * 0.1;
	time_start = time_act;
}
