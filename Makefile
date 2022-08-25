# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/08/24 19:15:57 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=cub3d
NAME_BONUS=cub3d_bonus

SRCS=$(addprefix srcs/, cub3d.c\
						exit.c\
						init_lsts.c\
						free_lsts.c\
						update_lsts.c\
						parsing_1.c\
						parsing_2.c\
						parsing_3.c\
						parsing_4.c\
						parsing_5.c\
						load_textures.c\
						hook.c\
						movement.c\
						draw_scene.c\
						draw_pov.c\
						draw_pov_utils_1.c\
						draw_pov_utils_2.c\
						draw_minimap.c\
						aff_maps.c)
SRCS_BONUS=$(addprefix srcs/, cub3d.c\
						exit.c\
						init_lsts.c\
						free_lsts.c\
						update_lsts.c\
						parsing_1.c\
						parsing_2.c\
						parsing_3.c\
						parsing_4.c\
						parsing_5.c\
						load_textures.c\
						hook.c\
						movement.c\
						draw_scene.c\
						draw_pov.c\
						draw_pov_utils_1.c\
						draw_pov_utils_2.c\
						draw_minimap.c\
						aff_maps.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

INCS=includes/cub3d.h
INCLUDES=$(addprefix -I , $(INCS))

NAME_LIBFT=libft
NAME_GNL=get_next_line
LIBFT=includes/libft
GNL=includes/gnl
MLX=includes/mlx

CC=clang -g
CFLAGS=-Wall -Wextra -Werror -g3
CMLXFLAGS= -L/usr/lib -lXext -lX11 -L$(MLX) -lm -lz
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL)
	make -C $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ $(CMLXFLAGS) $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL)
	make -C $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ $(CMLXFLAGS) $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	make clean -C $(MLX)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
	make all

re_bonus: fclean bonus
			make all
# valgrind --leak-check=full --show-leak-kinds=all ./cub3d maps/test.cub 2> leak.log