/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:24 by cmaginot          #+#    #+#             */
/*   Updated: 2021/04/19 16:46:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strdst;
	unsigned char	*strsrc;
	size_t			i;

	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	i = -1;
	if (dst > src)
		while (++i < len)
			strdst[len - i - 1] = strsrc[len - i - 1];
	else
		while (++i < len)
			strdst[i] = strsrc[i];
	return (dst);
}
