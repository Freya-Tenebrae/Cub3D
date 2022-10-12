/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/04 21:23:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		error("invalid map, map not sourronded by 1", maps);
}

void	check_map_validity(t_maps **maps)
{
	t_tiles	*tileptr;
	int		player_on_map;

	tileptr = (*maps)->tiles;
	player_on_map = 0;
	while (tileptr != NULL)
	{
		if (tileptr->type != '1')
		{
			check_sourrounding_void(maps, tileptr->x_pos, tileptr->y_pos);
			if (tileptr->type != '0')
				player_on_map = 1;
		}
		tileptr = tileptr->next;
	}
	if (player_on_map == 0)
		error("invalid map, no starting position", maps);
}

void	add_id_floor_color(t_maps **maps, char **l, int i)
{
	if ((*maps)->color_f != NULL)
	{
		free(*l);
		error("parsing : second definition of floor's color", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no value on floor's color", maps);
	}
	(*maps)->color_f = dup_color(l, i, maps);
	if ((*maps)->color_f == NULL)
		error("malloc error", maps);
}

void	add_id_ceiling_color(t_maps **maps, char **l, int i)
{
	if ((*maps)->color_c != NULL)
	{
		free(*l);
		error("parsing : second definition of ceiling's color", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no value on ceiling's color", maps);
	}
	(*maps)->color_c = dup_color(l, i, maps);
	if ((*maps)->color_c == NULL)
		error("malloc error", maps);
}
