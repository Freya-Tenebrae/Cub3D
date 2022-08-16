/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:14:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/21 16:39:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */
int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	*ft_memchr_gnl(const void *s, int c, size_t n);
char	*ft_strndup_gnl(const char *s1, size_t n);
void	*ft_memset_gnl(void *b, int c, size_t len);

#endif
