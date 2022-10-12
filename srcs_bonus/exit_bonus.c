/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:48:49 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/12 06:25:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	tutorial(t_maps **maps)
{
	ft_putstr_fd("The purpose of this game is to reach the exit\n", 1);
	ft_putstr_fd("You can :\n", 1);
	ft_putstr_fd(" - Leave the game with the key \"esc\".\n", 1);
	ft_putstr_fd(" - Move with \"wasd\" keys.\n", 1);
	ft_putstr_fd(" - Look Around With \"↑←↓→\" keys.\n", 1);
	ft_putstr_fd(" - Grab Parchemet and Open door with \"e\" key.\n", 1);
	ft_putstr_fd(" - Transform a witch into a cat for a few seconds ", 1);
	ft_putstr_fd("with left click. (only one witch can be transformed at", 1);
	ft_putstr_fd(" a time)\n", 1);
	free_maps(maps);
	exit(EXIT_SUCCESS);
}

void	success(t_maps **maps)
{
	ft_putstr_fd("\033[0;36m    ______     _ __  __\n", 1);
	ft_putstr_fd("   / ____/  __(_) /_/ /\n", 1);
	ft_putstr_fd("  / __/ | |/_/ / __/ / \n", 1);
	ft_putstr_fd(" / /____>  </ / /_/_/  \n", 1);
	ft_putstr_fd("/_____/_/|_/_/\\__(_)   \n\033[0m", 1);
	free_maps(maps);
	exit(EXIT_SUCCESS);
}

void	win(t_maps **maps)
{
	ft_putstr_fd("\033[0;32m__  __               _       __            __\n", 1);
	ft_putstr_fd("\\ \\/ /___  __  __   | |     / /___  ____  / /\n", 1);
	ft_putstr_fd(" \\  / __ \\/ / / /   | | /| / / __ \\/ __ \\/ / \n", 1);
	ft_putstr_fd(" / / /_/ / /_/ /    | |/ |/ / /_/ / / / /_/  \n", 1);
	ft_putstr_fd("/_/\\____/\\__,_/     |__/|__/\\____/_/ /_(_)   \n\033[0m", 1);
	free_maps(maps);
	exit(EXIT_SUCCESS);
}

void	game_over(t_maps **maps)
{
	ft_putstr_fd("\033[0;31m__  __               __                     ", 1);
	ft_putstr_fd("     __\n", 1);
	ft_putstr_fd("\\ \\/ /___  __  __   / /   ____  ____  ________  / /\n", 1);
	ft_putstr_fd(" \\  / __ \\/ / / /  / /   / __ \\/ __ \\/ ___/ _ \\/ / \n", 1);
	ft_putstr_fd(" / / /_/ / /_/ /  / /___/ /_/ / /_/ (__  )  __/_/ \n", 1);
	ft_putstr_fd("/_/\\____/\\__,_/  /_____/\\____/\\____/____/\\___(_) \n\033[0m", 1);
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
