/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:24 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/20 11:36:08 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;
	size_t	dest_l;
	size_t	result;

	i = 0;
	src_l = ft_strlen(src);
	dest_l = ft_strlen(dst);
	if (dstsize == 0)
		return (src_l);
	if (dstsize < dest_l)
		result = src_l + dstsize;
	else
		result = src_l + dest_l;
	while (src[i++] != '\0' && ((i + dest_l) < (dstsize)))
		dst[i + dest_l - 1] = src[i - 1];
	dst[i + dest_l - 1] = '\0';
	return (result);
}
