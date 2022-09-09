/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 08:24:02 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	add_pos_player(t_maps **maps, char **l, int i, int n_line)
{
	if ((*maps)->x_pos != 0 || (*maps)->y_pos != 0)
	{
		free(*l);
		error("parsing : second definition of character start", maps);
	}
	(*maps)->x_pos = (double)i + 0.5;
	(*maps)->y_pos = (double)n_line + 0.5;
	if ((*l)[i] == 'N')
		(*maps)->angle_h = 0;
	else if ((*l)[i] == 'E')
		(*maps)->angle_h = 0.5;
	else if ((*l)[i] == 'S')
		(*maps)->angle_h = 1;
	else if ((*l)[i] == 'W')
		(*maps)->angle_h = 1.5;
}

static void	add_tiles(t_maps **maps, char **l, int i, int n_line)
{
	t_tiles	*tmptile;

	if ((*l)[i] != ' ')
	{
		tmptile = init_tile(maps, l);
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
		if ((*l)[i] == '0' || (*l)[i] == '1' || (*l)[i] == '2' || \
			(*l)[i] == '3' || (*l)[i] == '4' || (*l)[i] == '5' || \
			(*l)[i] == '6' || (*l)[i] == 'N' || (*l)[i] == 'S' || \
			(*l)[i] == 'E' || (*l)[i] == 'W' || (*l)[i] == 'A' || \
			(*l)[i] == 'a' || (*l)[i] == 'B' || (*l)[i] == 'b' || \
			(*l)[i] == 'C' || (*l)[i] == 'c' || (*l)[i] == 'D' || \
			(*l)[i] == 'd' || (*l)[i] == 'F' || (*l)[i] == 'f' || \
			(*l)[i] == 'G' || (*l)[i] == 'g' || (*l)[i] == 'H' || \
			(*l)[i] == 'h' || (*l)[i] == ' ')
			add_tiles(maps, l, i, n_line);
		else
		{
			free(*l);
			error("parsing : invalid character on map", maps);
		}
		i++;
	}
	free(*l);
}
