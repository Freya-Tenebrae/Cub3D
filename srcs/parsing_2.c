/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 16:55:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_id(t_maps **maps, char **l)
{
	int	i;

	i = 0;
	while ((*l)[i] == ' ')
		i++;
	if ((*l)[i] == '\0')
		free (*l);
	else if ((*l)[i] == 'N' && (*l)[i + 1] == 'O' && (*l)[i + 2] == ' ')
		add_id_north(maps, l, i + 3);
	else if ((*l)[i] == 'S' && (*l)[i + 1] == 'O' && (*l)[i + 2] == ' ')
		add_id_south(maps, l, i + 3);
	else if ((*l)[i] == 'E' && (*l)[i + 1] == 'A' && (*l)[i + 2] == ' ')
		add_id_east(maps, l, i + 3);
	else if ((*l)[i] == 'W' && (*l)[i + 1] == 'E' && (*l)[i + 2] == ' ')
		add_id_west(maps, l, i + 3);
	else if ((*l)[i] == 'F' && (*l)[i + 1] == ' ')
		add_id_floor_color(maps, l, i + 2);
	else if ((*l)[i] == 'C' && (*l)[i + 1] == ' ')
		add_id_ceiling_color(maps, l, i + 2);
	else
	{
		free(*l);
		error("parsing : incorrect identifier", maps);
	}
}

static void	add_pos_player(t_maps **maps, char **l, int i, int n_line)
{
	if ((*maps)->x_pos != 0 || (*maps)->y_pos != 0)
	{
		free(*l);
		error("malloc error", maps);
	}
	(*maps)->x_pos = (double)i;
	(*maps)->y_pos = (double)n_line;
	if ((*l)[i] == 'N')
		(*maps)->angle = 0;
	if ((*l)[i] == 'S')
		(*maps)->angle = 180;
	if ((*l)[i] == 'E')
		(*maps)->angle = 90;
	if ((*l)[i] == 'W')
		(*maps)->angle = 270;
}

static void	add_tiles(t_maps **maps, char **l, int i, int n_line)
{
	t_tiles	*tmptile;

	if ((*l)[i] != ' ')
	{
		tmptile = init_tile();
		if (tmptile == NULL)
		{
			free(*l);
			error("malloc error", maps);
		}
		tmptile->x_pos = i;
		tmptile->y_pos = n_line;
		tmptile->type = (*l)[i];
		if (tmptile->x_pos > (*maps)->x_lenght)
			(*maps)->x_lenght = tmptile->x_pos;
		if (tmptile->y_pos > (*maps)->y_lenght)
			(*maps)->y_lenght = tmptile->y_pos;
		push_tiles_back(maps, tmptile);
		if ((*l)[i] == 'N' || (*l)[i] == 'S' || (*l)[i] == 'E' || \
			(*l)[i] == 'W')
			add_pos_player(maps, l, i, n_line);
	}
}

void	add_line_on_map(t_maps **maps, char **l, int n_line)
{
	int		i;

	i = 0;
	while ((*l)[i] != '\0')
	{
		if ((*l)[i] == '1' || (*l)[i] == '0' || (*l)[i] == 'N' || \
			(*l)[i] == 'S' || (*l)[i] == 'E' || (*l)[i] == 'W' || \
			(*l)[i] == ' ')
			add_tiles(maps, l, i, n_line);
		else
		{
			free(*l);
			error("parsing : incalid character on map", maps);
		}
		i++;
	}
	free(*l);
}
