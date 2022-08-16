/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:24 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/20 11:44:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*res;

	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len]) != 0)
		len--;
	res = ft_substr((char *)s1, 0, len + 1);
	return (res);
}
