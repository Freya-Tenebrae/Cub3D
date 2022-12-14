/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:41:24 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:19:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	unstransform_all_witch(t_maps **maps)
{
	t_actor		*actorptr;

	actorptr = (*maps)->actor;
	while (actorptr != NULL)
	{
		actorptr->type = ft_tolower(actorptr->type);
		actorptr->time_down = 0;
		actorptr = actorptr->next;
	}
}

static void	transform_a_witch(t_actor **actorptr)
{
	(*actorptr)->type = ft_toupper((*actorptr)->type);
	(*actorptr)->time_down = TIME_DOWN;
}

static int	actor_is_hit(t_maps **maps, t_entitie *entitie)
{
	int	count_x;

	pre_calc_raycasting_entities(*maps, entitie);
	count_x = entitie->start[0] -1;
	while (++(count_x) < entitie->end[0])
	{
		if (count_x == WINDOWS_SIZE_X / 2 && entitie->depth > 0 && \
			entitie->depth < (*maps)->z_buffer[count_x] && entitie->depth < 5)
			return (1);
	}
	return (0);
}

static void	action_transformation_execute(t_maps **maps)
{
	t_entitie	entitie;
	t_actor		*actorptr;

	entitie.direction[0] = sin((*maps)->angle_h * M_PI);
	entitie.direction[1] = -cos((*maps)->angle_h * M_PI);
	entitie.plane[0] = sin(((*maps)->angle_h + 0.5) * M_PI);
	entitie.plane[1] = -cos(((*maps)->angle_h + 0.5) * M_PI);
	actorptr = (*maps)->actor;
	while (actorptr != NULL)
	{
		entitie.pos_absolute[0] = actorptr->x_pos;
		entitie.pos_absolute[1] = actorptr->y_pos;
		unstransform_all_witch(maps);
		if (actor_is_hit(maps, &entitie) == 1)
			transform_a_witch(&actorptr);
		actorptr = actorptr->next;
	}
}

void	action_transformation(t_maps **maps)
{
	int	i;

	i = N_SPELL;
	while (--i >= 0)
	{
		if ((*maps)->spells[i] == 0)
		{
			(*maps)->spells[i] = TIME_DOWN * 2;
			action_transformation_execute(maps);
			break ;
		}
	}
}
