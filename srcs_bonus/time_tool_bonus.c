/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tool_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:40:47 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/11 20:22:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static unsigned long	get_time(void)
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
	static unsigned long	time_act;

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

static void	move_actor(t_maps **maps, t_actor **actor, int speed)
{
	if ((*actor)->type == 'x' || (*actor)->type == 'X')
	{
		(*actor)->x_pos += ACTOR_MOVE * speed * (*maps)->movement_factor / \
			4 * (*actor)->direction;
		if (actor_is_in_wall(maps, (*actor)->x_pos, (*actor)->y_pos) == 1)
		{
			(*actor)->direction *= -1;
			(*actor)->x_pos += ACTOR_MOVE * speed * (*maps)->movement_factor / \
				4 * (*actor)->direction;
		}
	}
	if ((*actor)->type == 'y' || (*actor)->type == 'Y')
	{
		(*actor)->y_pos += ACTOR_MOVE * speed * (*maps)->movement_factor / \
			4 * (*actor)->direction;
		if (actor_is_in_wall(maps, (*actor)->x_pos, (*actor)->y_pos) == 1)
		{
			(*actor)->direction *= -1;
			(*actor)->y_pos += ACTOR_MOVE * speed * (*maps)->movement_factor / \
				4 * (*actor)->direction;
		}
	}
}

void	update_actor(t_maps **maps)
{
	static unsigned long	time_start;
	static unsigned long	time_act;
	t_actor					*tmp_actor;

	if (!time_start)
		time_start = get_time();
	time_act = get_time();
	tmp_actor = (*maps)->actor;
	while (tmp_actor != NULL)
	{
		if (time_act - time_start >= 1000)
		{
			if (tmp_actor->type == 'X' && tmp_actor->time_down == 0)
				tmp_actor->type = 'x';
			else if (tmp_actor->type == 'Y' && tmp_actor->time_down == 0)
				tmp_actor->type = 'y';
			else if (tmp_actor->time_down != 0)
				tmp_actor->time_down--;
		}
		if (tmp_actor->type == 'x' || tmp_actor->type == 'y')
			move_actor(maps, &tmp_actor, 2);
		else
			move_actor(maps, &tmp_actor, 1);
		tmp_actor = tmp_actor->next;
	}
}

void	get_movement_factor(t_maps **maps)
{
	static unsigned long	time_start;
	static unsigned long	time_act;

	if (!time_start)
		time_start = get_time();
	time_act = get_time();
	(*maps)->movement_factor = (time_act - time_start) * 0.1;
	time_start = time_act;
}
