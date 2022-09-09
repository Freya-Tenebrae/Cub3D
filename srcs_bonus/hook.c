/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 06:05:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	close_hook(t_maps **maps)
{
	success(maps);
	return (0);
}

void	event_hook(t_maps **maps)
{
	event_hook_key(maps);
	event_hook_mouse(maps);
	mlx_hook((*maps)->mlx_win, 17, 1L << 17, close_hook, maps);
}
