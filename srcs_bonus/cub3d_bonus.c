/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:04:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/23 07:30:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	parsing(t_maps **maps)
{
	(*maps)->n_maps += 1;
	if ((*maps)->n_maps == 1)
		get_map(maps, MAPS_1);
	else if ((*maps)->n_maps == 2)
		get_map(maps, MAPS_2);
	else if ((*maps)->n_maps == 3)
		get_map(maps, MAPS_3);
	else if ((*maps)->n_maps == 4)
		get_map(maps, MAPS_4);
	else
		error("maps's number error", maps);
	check_map_validity(maps);
	(*maps)->status_game = RUNNING;
}

static void	loop_game_over(t_maps **maps)
{
	if ((*maps)->status_game == GAME_OVER_LOOSE)
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
			WINDOWS_SIZE_X / 2 - 4.5 * 6, WINDOWS_SIZE_Y / 2 - 6, COLOR_TEXT, \
			"Game over");
	if ((*maps)->status_game == GAME_OVER_WIN)
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
			WINDOWS_SIZE_X / 2 - 3.5 * 6, WINDOWS_SIZE_Y / 2 - 6, COLOR_TEXT, \
			"You Won");
	if ((*maps)->status_game == GAME_OVER_LOOSE || \
		(*maps)->status_game == GAME_OVER_WIN)
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
			WINDOWS_SIZE_X / 2 - 12.5 * 6, WINDOWS_SIZE_Y / 2 + 6, COLOR_TEXT, \
			"Press \"Enter\" to continue");
}

static int	loop(t_maps **maps)
{
	if ((*maps)->status_game == WAITING && (*maps)->n_maps + 1 > N_MAPS)
			(*maps)->status_game = GAME_OVER_WIN;
	else if ((*maps)->status_game == WAITING)
	{
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
			WINDOWS_SIZE_X / 2 - 12.5 * 6, WINDOWS_SIZE_Y / 2, COLOR_TEXT, \
			"Press \"Enter\" to continue");
	}
	if ((*maps)->status_game == LOADING)
	{
		free_for_next_map(maps);
		parsing(maps);
	}
	if ((*maps)->status_game == RUNNING)
	{
		update_frame(maps);
		get_movement_factor(maps);
		update_actor(maps);
		update_spell(maps);
		move(maps);
		actor_on_player(maps);
		draw_scene(maps);
	}
	loop_game_over(maps);
	return (0);
}

static void	aff_name_and_notice_terminal(void)
{
	ft_putstr_fd("\033[0;35m _       ___ __       __   _          ______\n", 1);
	ft_putstr_fd("| |     / (_) /______/ /_ ( )_____   / ____/", 1);
	ft_putstr_fd("_____________ _____  ___\n", 1);
	ft_putstr_fd("| | /| / / / __/ ___/ __ \\|// ___/  / __/ /", 1);
	ft_putstr_fd(" ___/ ___/ __ `/ __ \\/ _ \\\n", 1);
	ft_putstr_fd("| |/ |/ / / /_/ /__/ / / / (__  )  / /___(__", 1);
	ft_putstr_fd("  ) /__/ /_/ / /_/ /  __/\n", 1);
	ft_putstr_fd("|__/|__/_/\\__/\\___/_/ /_/ /____/  /_____/_", 1);
	ft_putstr_fd("___/\\___/\\__,_/ .___/\\___/ \n", 1);
	ft_putstr_fd("                                            ", 1);
	ft_putstr_fd("           /_/\n\033[0m", 1);
	ft_putstr_fd("The purpose of this game is to reach the exit\n", 1);
	ft_putstr_fd("You can :\n", 1);
	ft_putstr_fd(" - Leave the game with the key \"esc\".\n", 1);
	ft_putstr_fd(" - Move with \"wasd\" keys.\n", 1);
	ft_putstr_fd(" - Look Around With \"↑←↓→\" keys.\n", 1);
	ft_putstr_fd(" - Grab Parchemet and Open door with \"e\" key.\n", 1);
	ft_putstr_fd(" - Transform a witch into a cat for a few seconds ", 1);
	ft_putstr_fd("with left click or \"q\" key. (only one witch can be ", 1);
	ft_putstr_fd("transformed at a time)\n", 1);
}

int	main(void)
{
	t_maps	*maps;

	maps = init_maps();
	maps->mlx = mlx_init();
	if (!(maps->mlx))
		error("initiatisation of mlx failed", &maps);
	maps->mlx_win = mlx_new_window(maps->mlx, WINDOWS_SIZE_X, \
													WINDOWS_SIZE_Y, "cub3d");
	if (!(maps->mlx_win))
		error("initiatisation of mlx windows failed", &maps);
	event_hook(&maps);
	aff_name_and_notice_terminal();
	check_validity_textures(&maps);
	load_textures(&maps);
	mlx_loop_hook(maps->mlx, loop, &maps);
	mlx_loop(maps->mlx);
	error("mlx_loop stoped working unexpectedly", &maps);
	return (0);
}
