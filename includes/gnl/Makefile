# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 15:31:00 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/20 15:50:32 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=get_next_line.a
SRCS=get_next_line.c get_next_line_utils.c
SRCS_BONUS=get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
BUFFER_SIZE=32

all: $(NAME)

$(NAME): fclean $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: fclean $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) -c $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
