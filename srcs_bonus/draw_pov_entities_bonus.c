/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_entities_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:24:51 by cmaginot          #+#    #+#             */
/*   Updated: 2022/10/30 04:19:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	get_right_color_texture(t_maps *maps, t_texture_entitie *text)
{
	int	skip_to_right_texture;
	int	skip_to_right_lign;
	int	skip_to_right_frame;

	skip_to_right_texture = text->number_texture * N_FRAME * TEXTURE_SIZE_X * \
							TEXTURE_SIZE_Y;
	skip_to_right_lign = N_FRAME * TEXTURE_SIZE_X * text->texture_position[1];
	skip_to_right_frame = maps->n_frame * TEXTURE_SIZE_X;
	return ((maps->textures_entities->data)[skip_to_right_texture + \
		skip_to_right_lign + skip_to_right_frame + text->texture_position[0]]);
}

static void	draw_entitie_2(t_maps **maps, t_entitie *entitie, \
										t_texture_entitie *text, int count[2])
{
	int	color;

	text->pos_start_texture[1] = text->step * (entitie->start[1] - \
		WINDOWS_SIZE_Y / 2 + entitie->height_and_width / 2 - \
		(*maps)->pitch);
	count[1] = entitie->start[1] -1;
	while (++(count[1]) < entitie->end[1])
	{
		text->texture_position[1] = (int)text->pos_start_texture[1] & \
												(TEXTURE_SIZE_Y - 1);
		text->pos_start_texture[1] += text->step;
		color = get_right_color_texture(*maps, text);
		if (color != 65280)
			(*maps)->img->data[count[1] * WINDOWS_SIZE_X + \
				count[0]] = color;
	}
}

static void	draw_entitie(t_maps **maps, t_entitie *entitie, char type)
{
	int					count[2];
	t_texture_entitie	text;

	pre_calc_raycasting_entities(*maps, entitie);
	get_number_text_and_step_actor(entitie, &text, type);
	count[0] = entitie->start[0] -1;
	while (++(count[0]) < entitie->end[0])
	{
		text.texture_position[0] = (int)text.pos_start_texture[0] & \
														(TEXTURE_SIZE_X - 1);
		text.pos_start_texture[0] += text.step;
		if (count[0] > 0 && count[0] < WINDOWS_SIZE_X && entitie->depth > 0 && \
			entitie->depth < (*maps)->z_buffer[count[0]])
			draw_entitie_2(maps, entitie, &text, count);
	}
}

void	draw_actors(t_maps **maps, t_entitie *entitie)
{
	t_actor		*actorptr;

	sort_actor_from_distance(maps);
	actorptr = (*maps)->actor;
	while (actorptr != NULL)
	{
		entitie->pos_absolute[0] = actorptr->x_pos;
		entitie->pos_absolute[1] = actorptr->y_pos;
		draw_entitie(maps, entitie, actorptr->type);
		actorptr = actorptr->next;
	}
}

void	draw_entities(t_maps **maps)
{
	t_entitie	entitie;
	t_tiles		*tileptr;

	entitie.direction[0] = sin((*maps)->angle_h * M_PI);
	entitie.direction[1] = -cos((*maps)->angle_h * M_PI);
	entitie.plane[0] = sin(((*maps)->angle_h + 0.5) * M_PI);
	entitie.plane[1] = -cos(((*maps)->angle_h + 0.5) * M_PI);
	tileptr = (*maps)->tiles;
	while (tileptr != NULL)
	{
		if ((tileptr->type >= 'a' && tileptr->type <= 'd') || \
			(tileptr->type >= 'f' && tileptr->type <= 'h'))
		{
			entitie.pos_absolute[0] = tileptr->x_pos + 0.5;
			entitie.pos_absolute[1] = tileptr->y_pos + 0.5;
			draw_entitie(maps, &entitie, tileptr->type);
		}
		tileptr = tileptr->next;
	}
	draw_actors(maps, &entitie);
}
