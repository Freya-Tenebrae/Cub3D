/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:24 by cmaginot          #+#    #+#             */
/*   Updated: 2021/05/25 14:50:21 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*res;
	size_t	lenstr;

	if (s == 0)
		return (0);
	lenstr = ft_strlen(s);
	if (lenstr < start)
		str = malloc(1 * sizeof(char));
	else if (lenstr - start < len)
		str = malloc((lenstr - start + 1) * sizeof(char));
	else
		str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	res = str;
	while (*s != '\0' && start-- > 0)
		s++;
	while (*s != '\0' && len-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (res);
}
