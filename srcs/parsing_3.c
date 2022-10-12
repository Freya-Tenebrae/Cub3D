/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/05 07:16:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*dup_path_value(char **l, int i, t_maps **maps)
{
	char	*str;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while ((*l)[i + j] != ' ' && (*l)[i + j] != '\0')
		j++;
	if ((*l)[i + j] != ' ')
	{
		while ((*l)[i + j + k] == ' ')
			k++;
		if ((*l)[i + j + k] != '\0')
		{
			free(*l);
			error("parsing : a texture can't take two path", maps);
		}
	}
	str = ft_strndup(&((*l)[i]), j);
	free(*l);
	return (str);
}

void	add_id_north(t_maps **maps, char **l, int i)
{
	if ((*maps)->texture_n != NULL)
	{
		free(*l);
		error("parsing : second definition of north's texture", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no path on north's texture", maps);
	}
	(*maps)->texture_n = dup_path_value(l, i, maps);
	if ((*maps)->texture_n == NULL)
		error("malloc error", maps);
}

void	add_id_south(t_maps **maps, char **l, int i)
{
	if ((*maps)->texture_s != NULL)
	{
		free(*l);
		error("parsing : second definition of south's texture", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no path on south's texture", maps);
	}
	(*maps)->texture_s = dup_path_value(l, i, maps);
	if ((*maps)->texture_s == NULL)
		error("malloc error", maps);
}

void	add_id_east(t_maps **maps, char **l, int i)
{
	if ((*maps)->texture_e != NULL)
	{
		free(*l);
		error("parsing : second definition of east's texture", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no path on east's texture", maps);
	}
	(*maps)->texture_e = dup_path_value(l, i, maps);
	if ((*maps)->texture_e == NULL)
		error("malloc error", maps);
}

void	add_id_west(t_maps **maps, char **l, int i)
{
	if ((*maps)->texture_w != NULL)
	{
		free(*l);
		error("parsing : second definition of west's texture", maps);
	}
	while (ft_isspace((*l)[i]))
		i++;
	if ((*l)[i] == '\0')
	{
		free (*l);
		error("parsing : no path on west's texture", maps);
	}
	(*maps)->texture_w = dup_path_value(l, i, maps);
	if ((*maps)->texture_w == NULL)
		error("malloc error", maps);
}
