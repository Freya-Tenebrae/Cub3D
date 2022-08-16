/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:15:19 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/20 11:39:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	if (len == 0)
		return (dst);
	if (src[0] != '\0')
		while (src[++i] != '\0' && i < len)
			dst[i] = src[i];
	else
		dst[++i] = '\0';
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}
