/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:48:49 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 06:05:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	success(t_maps **maps)
{
	ft_putstr_fd("\033[0;32mThe program 'cub3d' has been correclty ", 1);
	ft_putstr_fd("executed.\n\033[0m", 1);
	free_maps(maps);
	exit(EXIT_SUCCESS);
}

void	error(char *str, t_maps **maps)
{
	ft_putstr_fd("\033[0;31mError :\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("!\n\033[0m", 2);
	free_maps(maps);
	exit(EXIT_FAILURE);
}
