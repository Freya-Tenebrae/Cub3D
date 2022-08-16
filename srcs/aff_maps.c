/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:01:10 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/16 17:19:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	aff1(t_maps *maps)
{
	ft_putstr("north : ");
	ft_putstr(maps->texture_n);
	ft_putchar('\n');
	ft_putstr("south : ");
	ft_putstr(maps->texture_s);
	ft_putchar('\n');
	ft_putstr("west : ");
	ft_putstr(maps->texture_w);
	ft_putchar('\n');
	ft_putstr("east : ");
	ft_putstr(maps->texture_e);
	ft_putchar('\n');
	ft_putstr("floor : ");
	ft_putstr(maps->color_f);
	ft_putchar('\n');
	ft_putstr("ceiling : ");
	ft_putstr(maps->color_c);
	ft_putchar('\n');
	ft_putstr("map : \n");
}

static void	aff2(t_tiles *ptr)
{
	int	n;

	n = 0;
	ft_putchar(ptr->type);
	if (ptr->next != NULL && (ptr->y_pos - ptr->next->y_pos) != 0)
	{
		ft_putchar('\n');
		n = 0;
		while (n++ < ptr->next->x_pos)
			ft_putchar(' ');
	}
	if (ptr->next != NULL && ptr->x_pos - ptr->next->x_pos != -1)
	{
		n = 0;
		while (n++ < (ptr->x_pos - ptr->next->x_pos) * -1 - 1)
			ft_putchar(' ');
	}
}

static void	aff3(t_maps *maps)
{
	ft_putchar('\n');
	ft_putstr("x_lenght : ");
	ft_putnbr(maps->x_lenght);
	ft_putchar('\n');
	ft_putstr("y_lenght : ");
	ft_putnbr(maps->y_lenght);
	ft_putchar('\n');
	ft_putstr("pos_player_x : ");
	ft_putnbr(maps->x_pos);
	ft_putchar('\n');
	ft_putstr("pos_player_y : ");
	ft_putnbr(maps->y_pos);
	ft_putchar('\n');
	ft_putstr("angle player : ");
	ft_putnbr(maps->angle);
	ft_putchar('\n');
}

void	affmap(t_maps *maps)
{
	t_tiles	*ptr;
	int		n;

	n = 0;
	ptr = maps->tiles;
	aff1(maps);
	while (n++ < maps->tiles->x_pos)
		ft_putchar(' ');
	while (ptr != NULL)
	{
		aff2(ptr);
		ptr = ptr->next;
	}
	aff3(maps);
}
