/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:24 by freya             #+#    #+#             */
/*   Updated: 2021/05/20 11:13:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_setresult(size_t value, int sign, int i)
{
	if (i > 19 || value > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (value * sign);
}

size_t	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	value;

	i = 0;
	sign = 1;
	value = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str <= '\r'))
		str++;
	if (*str != '\0' && str[i] == '-')
	{
		sign *= -1;
		str++;
	}
	else if (str[i] != '\0' && str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (ft_setresult(value, sign, i));
}
