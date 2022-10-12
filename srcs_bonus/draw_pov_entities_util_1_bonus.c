/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_entities_util_1_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/12 05:36:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	swap_actor(t_actor **actor1, t_actor **actor2)
{
	t_actor	tmp_actor;

	tmp_actor.type = (*actor1)->type;
	tmp_actor.x_pos = (*actor1)->x_pos;
	tmp_actor.y_pos = (*actor1)->y_pos;
	tmp_actor.time_down = (*actor1)->time_down;
	tmp_actor.direction = (*actor1)->direction;
	(*actor1)->type = (*actor2)->type;
	(*actor1)->x_pos = (*actor2)->x_pos;
	(*actor1)->y_pos = (*actor2)->y_pos;
	(*actor1)->time_down = (*actor2)->time_down;
	(*actor1)->direction = (*actor2)->direction;
	(*actor2)->type = tmp_actor.type;
	(*actor2)->x_pos = tmp_actor.x_pos;
	(*actor2)->y_pos = tmp_actor.y_pos;
	(*actor2)->time_down = tmp_actor.time_down;
	(*actor2)->direction = tmp_actor.direction;
}

void	sort_actor_from_distance(t_maps **maps)
{
	t_actor	*actor;
	t_actor	*actorptr1;
	t_actor	*actorptr2;

	actor = (*maps)->actor;
	actorptr1 = actor;
	while (actorptr1 != NULL)
	{
		actorptr2 = actorptr1->next;
		while (actorptr2 != NULL)
		{
			if (fabs(actorptr2->x_pos - (*maps)->x_pos) + \
				fabs(actorptr2->y_pos - (*maps)->y_pos) > \
				fabs(actorptr1->x_pos - (*maps)->x_pos) + \
				fabs(actorptr1->y_pos - (*maps)->y_pos))
				swap_actor(&actorptr1, &actorptr2);
			actorptr2 = actorptr2->next;
		}
		actorptr1 = actorptr1->next;
	}
}
