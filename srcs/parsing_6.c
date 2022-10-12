/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:42:18 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/05 03:06:53 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_color(char **l, int i, t_maps **maps)
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
	str = ft_strdup(&((*l)[i]));
	free(*l);
	return (str);
}

char	*parse_between_colors(t_maps **maps, char *s)
{
	while (ft_isspace(*s))
		s++;
	if (*s != ',')
		error("color value isn't correct", maps);
	s++;
	while (ft_isspace(*s))
		s++;
	return (s);
}

char	*parse_color(t_maps **maps, char *s)
{
	if (ft_isdigit(*s) != 1)
		error("color value isn't correct", maps);
	while (ft_isdigit(*s) == 1)
		s++;
	return (s);
}
