/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/21 16:36:30 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_updatestr(char **str)
{
	char	*tmp;
	char	*rest;

	tmp = *str;
	while (*tmp != '\n')
		tmp++;
	tmp++;
	rest = ft_strndup_gnl(tmp, ft_strlen_gnl(tmp));
	free(*str);
	*str = ft_strndup_gnl(rest, ft_strlen_gnl(rest));
	free(rest);
	if (!*str)
		return (-1);
	return (0);
}

static int	ft_add_buff_to_str(char **str, char **buf, int i)
{
	char	*res;

	if (i < 0)
	{
		free(*str);
		*str = NULL;
		free(*buf);
		return (-1);
	}
	(*buf)[i] = '\0';
	res = ft_strjoin_gnl(*str, *buf);
	free(*str);
	free(*buf);
	if (!res)
	{
		str = NULL;
		return (-1);
	}
	*str = res;
	return (0);
}

static int	ft_put_in_line(char **line, char **str)
{
	int		i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	*line = ft_strndup_gnl(*str, i);
	if (!*line)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	if ((*str)[i] == '\0')
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	if (ft_updatestr(str) != 0)
		return (-1);
	return (1);
}

static int	ft_read_line(int fd, char **str)
{
	int		i;
	char	*buf;

	i = 1;
	while (i != 0 && ft_memchr_gnl(*str, '\n', ft_strlen_gnl(*str) + 1) == 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
		{
			free(*str);
			*str = NULL;
			return (-1);
		}
		i = read(fd, buf, BUFFER_SIZE);
		if (ft_add_buff_to_str(str, &buf, i) != 0)
			return (-1);
	}
	if (!*str)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[1024];

	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!str[fd])
	{
		str[fd] = ft_strndup_gnl("", 0);
		if (!str[fd])
			return (-1);
	}
	if (ft_read_line(fd, &(str[fd])) != 0)
		return (-1);
	return (ft_put_in_line(line, &(str[fd])));
}
