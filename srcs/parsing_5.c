/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:14:18 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/05 07:12:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_code_color(t_maps **maps, char *s)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(s);
	while (*s != ',')
		s++;
	s++;
	g = ft_atoi(s);
	while (*s != ',')
		s++;
	s++;
	b = ft_atoi(s);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		error ("color value out of range", maps);
	return (r << 16 | g << 8 | b);
}

void	check_if_correct_code(t_maps **maps, char *s)
{
	s = parse_color(maps, s);
	s = parse_between_colors(maps, s);
	s = parse_color(maps, s);
	s = parse_between_colors(maps, s);
	s = parse_color(maps, s);
	if (*s != '\0')
		error("color value isn't correct", maps);
}

void	check_color_value(t_maps **maps)
{
	check_if_correct_code(maps, (*maps)->color_c);
	check_if_correct_code(maps, (*maps)->color_f);
	(*maps)->code_color_c = get_code_color(maps, (*maps)->color_c);
	(*maps)->code_color_f = get_code_color(maps, (*maps)->color_f);
}
