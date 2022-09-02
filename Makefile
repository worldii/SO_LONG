# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghapa <jonghapa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 03:31:47 by jonghapark        #+#    #+#              #
#    Updated: 2022/09/02 13:33:13 by jonghapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= Libft
LIBFT_LIB	= libft.a

SRCS		= get_next_line.c \
			  get_next_line_utils.c \
			  so_long.c \
			  presskey.c \
			  init.c \
			  errorcheck.c \
			  end_game.c \

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)
$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
