/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 16:55:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_map(t_maps **maps, char **l)
{
	int	i;

	i = 0;
	if ((*maps)->tiles != NULL)
		return (1);
	else
	{
		while ((*l)[i] == ' ')
			i++;
		if ((*l)[i] == '1')
		{
			if ((*maps)->texture_n == NULL || (*maps)->texture_s == NULL || \
				(*maps)->texture_e == NULL || (*maps)->texture_w == NULL || \
				(*maps)->color_f == NULL || (*maps)->color_c == NULL )
				error("A texture or Color isn't defined by map", maps);
			return (1);
		}
	}
	return (0);
}

static void	pars_line(t_maps **maps, char **l, int *n_line, \
								int status_gnl)
{
	if (status_gnl == -1)
	{
		free (*l);
		error("parsing :  failed to read the file or line", maps);
	}
	else if (ft_strcmp(*l, "") == 0)
	{
		free (*l);
		if ((*maps)->tiles != NULL && status_gnl == 1)
			error("parsing : empty line on maps", maps);
	}
	else if (is_map(maps, l) == 1)
	{
		add_line_on_map(maps, l, *n_line);
		*n_line += 1;
	}
	else
		add_id(maps, l);
}

static int	check_file_cub(const char *map_path)
{
	int		path_len;

	path_len = ft_strlen(map_path);
	if (path_len <= 4)
		return (-1);
	if (ft_strcmp(&(map_path[path_len - 4]), ".cub") != 0)
		return (-1);
	return (0);
}

void	get_map(t_maps **maps, const char *map_path)
{
	int		fd;
	int		status_gnl;
	int		n_line;
	char	*l;

	if (check_file_cub(map_path) != 0)
		error("parsing : incorrect file name", maps);
	fd = open(map_path, O_RDONLY);
	status_gnl = 1;
	n_line = 0;
	l = NULL;
	if (fd < 0)
		error("parsing : failed to load file", maps);
	while (status_gnl == 1)
	{
		status_gnl = get_next_line(fd, &l);
		pars_line(maps, &l, &n_line, status_gnl);
	}
	if (status_gnl == -1)
		error("parsing : GNL failed to read the file or line", maps);
	close(fd);
}
