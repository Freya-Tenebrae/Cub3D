/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:04:53 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/28 13:58:15 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_validity_texture(char *pathfile, t_maps **maps)
{
	int		nb_error;
	int		fd;
	char	*line;

	nb_error = 0;
	line = NULL;
	pathfile = ft_strdup(pathfile);
	fd = open(pathfile, O_RDONLY);
	if (fd < 0)
		nb_error = 1;
	else if (read(fd, line, 0) == -1)
		nb_error = 2;
	else if (ft_strncmp(ft_strrev(pathfile), "mpx.", 4) != 0
		|| !*(pathfile + 4) || *(pathfile + 4) == '/')
		nb_error = 3;
	free(pathfile);
	close(fd);
	if (nb_error == 1)
		error("parsing : Texture doesn't exist", maps);
	if (nb_error == 2)
		error("parsing : Texture is a directory", maps);
	if (nb_error == 3)
		error("parsing : Texture has the wrong extension", maps);
}

void	check_validity_textures(t_maps **maps)
{
	check_validity_texture((*maps)->texture_n, maps);
	check_validity_texture((*maps)->texture_s, maps);
	check_validity_texture((*maps)->texture_e, maps);
	check_validity_texture((*maps)->texture_w, maps);
}
