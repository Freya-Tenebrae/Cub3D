# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 18:50:10 by cmaginot          #+#    #+#              #
#    Updated: 2022/10/13 19:52:19 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME				=	cub3D

NAME_BONUS_1		=	Witch\'s_Escape

NAME_BONUS_2		=	catch_them_all

################
#   COMMANDS   #
################

CC					=	clang
LINK				=	clang
MKDIR				=	/usr/bin/mkdir -p
RM					=	/usr/bin/rm -rf

#############
#   FLAGS   #
#############

CFLAGS				=	-Wall -Wextra -Werror -c -g3
CFLAGS				+=	-I $(INCS)
CFLAGS				+=	-MMD -MP -I$(MLX_D) -I$(GNL_D) -I$(LIBFT_D)
LDFLAGS				=	-L$(LIBFT_D) -lft -lXext -lX11 -lm -L$(MLX_D) -lmlx -L$(GNL_D) -lgnl

###################
#   DIRECTORIES   #
###################

INCS				=	includes/

LIBFT_D				=	$(addprefix $(INCS), libft/)
MLX_D				=	$(addprefix $(INCS), mlx/)
GNL_D				=	$(addprefix $(INCS), gnl/)
SRCS_D				=	srcs/
SRCS_BONUS_D		=	srcs_bonus/
OBJS_D				=	objs/
OBJS_BONUS_D		=	objs_bonus/

##################
#   LIBRAIRIES   #
##################

LIBFT_A				=	libft.a
LIBFT_A				:=	$(addprefix $(LIBFT_D), $(LIBFT_A))

LIBMLX_A			=	libmlx.a
LIBMLX_A			:=	$(addprefix $(MLX_D), $(LIBMLX_A))

GNL_A				=	libgnl.a
GNL_A				:=	$(addprefix $(GNL_D), $(GNL_A))

###############
#   SOURCES   #
###############

SRCS				=	cub3d.c	\
						exit.c\
						init_lsts.c\
						free_lsts.c\
						update_lsts.c\
						parsing_1.c\
						parsing_2.c\
						parsing_3.c\
						parsing_4.c\
						parsing_5.c\
						parsing_6.c\
						load_textures.c\
						hook.c\
						hook_key.c\
						hook_mouse.c\
						movement.c\
						movement_out_of_wall.c\
						draw_scene.c\
						draw_pov.c\
						draw_pov_utils_1.c\
						draw_pov_utils_2.c\
						draw_minimap.c\
						aff_maps.c\
						check_validity_textures.c

SRCS_BONUS			=	cub3d_bonus.c	\
						exit_bonus.c\
						init_lsts_bonus.c\
						free_lsts_bonus.c\
						update_lsts_bonus.c\
						parsing_1_bonus.c\
						parsing_2_bonus.c\
						parsing_3_bonus.c\
						load_textures_bonus.c\
						hook_bonus.c\
						hook_key_bonus.c\
						hook_mouse_bonus.c\
						movement_bonus.c\
						movement_out_of_wall_bonus.c\
						draw_scene_bonus.c\
						draw_pov_bonus.c\
						draw_pov_floor_bonus.c\
						draw_pov_entities_bonus.c\
						draw_pov_utils_1_bonus.c\
						draw_pov_utils_2_bonus.c\
						draw_pov_entities_util_1_bonus.c\
						draw_pov_entities_util_2_bonus.c\
						draw_minimap_bonus.c\
						draw_ath_bonus.c\
						color_transparency_bonus.c\
						check_validity_textures_bonus.c\
						time_tool_bonus.c\
						update_actor_and_spells.c\
						actor_collision_bonus.c\
						action_key_bonus.c\
						action_mouse_bonus.c

###############
#   OBJECTS   #
###############

OBJS				=	$(SRCS:.c=.o)
OBJS				:=	$(addprefix $(OBJS_D), $(OBJS))


OBJS_BONUS			=	$(SRCS_BONUS:.c=.o)
OBJS_BONUS			:=	$(addprefix $(OBJS_BONUS_D), $(OBJS_BONUS))

####################
#   DEPENDENCIES   #
####################

DEP					=	$(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

#############
#   RULES   #
#############

all:					$(NAME)

$(NAME):				$(OBJS) $(LIBFT_A) $(LIBMLX_A) $(GNL_A)
						$(LINK) $(OBJS) $(LDFLAGS) $(OUTPUT_OPTION)

bonus:					$(NAME_BONUS_1)

$(NAME_BONUS_1):		$(OBJS_BONUS) $(LIBFT_A) $(LIBMLX_A) $(GNL_A)
						$(LINK) $(OBJS_BONUS) $(LDFLAGS) $(OUTPUT_OPTION)

-include				$(DEP)

$(OBJS_D)%.o:			$(SRCS_D)%.c
						$(MKDIR) $(@D)
						$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_D)%.o:			$(GNL_D)%.c
						$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_BONUS_D)%.o:		$(SRCS_BONUS_D)%.c
						$(MKDIR) $(@D)
						$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_BONUS_D)%.o:		$(GNL_D)%.c
						$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(MLX_D)libmlx.a:
						$(MAKE) -C $(MLX_D)

$(LIBFT_D)libft.a:
						$(MAKE) $(@F) -C $(@D) bonus

$(GNL_D)libgnl.a:
						$(MAKE) $(@F) -C $(@D)

clean:
					$(MAKE) clean -C $(MLX_D)
					$(MAKE) clean -C $(LIBFT_D)
					$(MAKE) clean -C $(GNL_D)
					$(RM) $(OBJS_D) $(OBJS_BONUS_D)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_D)
					$(MAKE) fclean -C $(GNL_D)
					$(RM) $(NAME) $(NAME_BONUS_1)

re:					fclean all

re_bonus:			fclean bonus

malloc_test:		$(OBJS) $(LIBFT_A) $(LIBMLX_A) $(GNL_A)
					$(LINK) $(LDFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} $(LIBFT_A) $(LIBMLX_A) $(GNL_A) -L. -lmallocator

.PHONY:				all clean fclean re bonus re_bonus

