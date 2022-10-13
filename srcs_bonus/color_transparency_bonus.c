/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_transparency_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:39:31 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/13 19:07:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	get_value_with_transparency(int base_color, int new_color, \
									double transparency)
{
	int	r[3];
	int	g[3];
	int	b[3];

	r[0] = (base_color >> 16) & 0xFF;
	r[1] = (new_color >> 16) & 0xFF;
	r[2] = (r[0] + r[1]) * transparency;
	g[0] = (base_color >> 8) & 0xFF;
	g[1] = (new_color >> 8) & 0xFF;
	g[2] = (g[0] + g[1]) * transparency;
	b[0] = base_color & 0xFF;
	b[1] = new_color & 0xFF;
	b[2] = (b[0] + b[1]) * transparency;
	return (r[2] << 16 | g[2] << 8 | b[2]);
}
