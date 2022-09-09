/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 08:34:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	check_sourrounding_void_in_loop(t_tiles *tileptr, \
								int *n_adjacent_tiles, int x_pos, int y_pos)
{
	if (tileptr->x_pos == x_pos - 1 && tileptr->y_pos == y_pos - 1)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos && tileptr->y_pos == y_pos - 1)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos + 1 && tileptr->y_pos == y_pos - 1)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos - 1 && tileptr->y_pos == y_pos)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos + 1 && tileptr->y_pos == y_pos)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos - 1 && tileptr->y_pos == y_pos + 1)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos && tileptr->y_pos == y_pos + 1)
		(*n_adjacent_tiles)++;
	else if (tileptr->x_pos == x_pos + 1 && tileptr->y_pos == y_pos + 1)
		(*n_adjacent_tiles)++;
}

static void	check_sourrounding_void(t_maps **maps, int x_pos, int y_pos)
{
	t_tiles	*tileptr;
	int		n_adjacent_tiles;

	tileptr = (*maps)->tiles;
	n_adjacent_tiles = 0;
	while (tileptr != NULL)
	{
		check_sourrounding_void_in_loop(tileptr, &n_adjacent_tiles, \
																x_pos, y_pos);
		tileptr = tileptr->next;
	}
	if (n_adjacent_tiles != 8)
		error("invalid map, map not sourronded by wall", maps);
}

void	check_map_validity(t_maps **maps)
{
	t_tiles	*tileptr;
	int		player_on_map;

	tileptr = (*maps)->tiles;
	player_on_map = 0;
	while (tileptr != NULL)
	{
		if (tileptr->type != '1' && tileptr->type != '2' && \
			tileptr->type != '3' && tileptr->type != '4' && \
			tileptr->type != '5' && tileptr->type != '6')
		{
			check_sourrounding_void(maps, tileptr->x_pos, tileptr->y_pos);
			if (tileptr->type == 'N' || tileptr->type == 'S' || \
				tileptr->type == 'E' || tileptr->type == 'W')
				player_on_map = 1;
		}
		tileptr = tileptr->next;
	}
	if (player_on_map == 0)
		error("invalid map, no starting position", maps);
}
