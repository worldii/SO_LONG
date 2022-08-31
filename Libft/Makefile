# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 14:50:35 by jonghapa          #+#    #+#              #
#    Updated: 2021/12/03 14:03:44 by jonghapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -c
CC = gcc

NAME =libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c  ft_toupper.c
OBJ = $(SRC:.c=.o)
BONUSSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		   ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUSOBJ = $(BONUSSRC:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJ) $(BONUSOBJ)
else
	OBJECTS = $(OBJ)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@


$(NAME) : $(OBJECTS)
	ar crs $@ $^

bonus : 
	@make WITH_BONUS=1 all

clean :
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)
re :fclean all
.PHONY: clean fclean re all
