# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 03:31:47 by jonghapark        #+#    #+#              #
#    Updated: 2022/08/31 14:15:53 by jonghapark       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= get_next_line.c \
			  get_next_line_utils.c \
			  so_long.c \
			  presskey.c \
			  init.c \
			  errorcheck.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		=  
#-Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		arch -x86_64 gcc -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		arch -x86_64 gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)
re			:	fclean all

.PHONY		:	all clean fclean re bonus
