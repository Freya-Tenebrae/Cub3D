/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor_collision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/12 06:03:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	actor_is_in_wall_2(t_maps **maps, double x, double y)
{
	t_tiles	*tiles_ptr;
	int		f_xpos;
	int		f_ypos;

	f_xpos = floor(x);
	f_ypos = floor(y);
	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		if (f_xpos == tiles_ptr->x_pos && f_ypos == tiles_ptr->y_pos)
		{
			if (((tiles_ptr->type >= '1' && tiles_ptr->type <= '6') || \
				(tiles_ptr->type >= 'A' && tiles_ptr->type <= 'D') || \
				(tiles_ptr->type >= 'F' && tiles_ptr->type <= 'H')))
				return (1);
			else
				return (0);
		}
		tiles_ptr = tiles_ptr->next;
	}
	return (0);
}

int	actor_is_in_wall(t_maps **maps, double x, double y)
{
	if (actor_is_in_wall_2(maps, x + 0.1, y + 0.1) == 1)
		return (1);
	if (actor_is_in_wall_2(maps, x - 0.1, y + 0.1) == 1)
		return (1);
	if (actor_is_in_wall_2(maps, x + 0.1, y - 0.1) == 1)
		return (1);
	if (actor_is_in_wall_2(maps, x - 0.1, y - 0.1) == 1)
		return (1);
	return (0);
}

void	actor_on_player(t_maps **maps)
{
	t_actor	*actorptr;

	actorptr = (*maps)->actor;
	while (actorptr != NULL)
	{
		if ((actorptr->x_pos - (*maps)->x_pos < 0.5) && \
			(actorptr->x_pos - (*maps)->x_pos > -0.5) && \
			(actorptr->y_pos - (*maps)->y_pos < 0.5) && \
			(actorptr->y_pos - (*maps)->y_pos > -0.5) && \
			(actorptr->type == 'x' || actorptr->type == 'y'))
			game_over(maps);
		actorptr = actorptr->next;
	}
}
