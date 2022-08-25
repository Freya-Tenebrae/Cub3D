/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lsts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/19 19:01:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
