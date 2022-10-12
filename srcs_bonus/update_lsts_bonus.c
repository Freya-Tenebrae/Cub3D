/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lsts_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/02 21:17:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	push_tiles_back(t_maps **maps, t_tiles *tiles_to_push)
{
	t_tiles	*tilesptr;

	tilesptr = (*maps)->tiles;
	if ((*maps)->tiles == NULL)
		(*maps)->tiles = tiles_to_push;
	else
	{
		while (tilesptr->next != NULL)
			tilesptr = tilesptr->next;
		tilesptr->next = tiles_to_push;
	}
}

void	push_actor_back(t_maps **maps, t_actor *actor_to_push)
{
	t_actor	*actorptr;

	actorptr = (*maps)->actor;
	if ((*maps)->actor == NULL)
		(*maps)->actor = actor_to_push;
	else
	{
		while (actorptr->next != NULL)
			actorptr = actorptr->next;
		actorptr->next = actor_to_push;
	}
}
