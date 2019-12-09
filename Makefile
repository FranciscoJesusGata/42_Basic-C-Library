# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 17:33:16 by fgata-va          #+#    #+#              #
#    Updated: 2019/12/03 20:59:32 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c \
ft_putstr_fd.c  ft_strjoin.c    ft_strlen.c     ft_strnstr.c    ft_substr.c ft_bzero.c \
ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_strchr.c \
ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c \
ft_itoa.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
ft_strtrim.c ft_toupper.c ft_split.c

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJS = $(BONUSSRC:.c=.o)

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)

bonus:
		@$(CC) $(CFLAGS) -c $(BONUSSRC) $(SRC)
		@ar rc $(NAME) $(OBJ) $(BONUSOBJS)

clean: 
		@rm -f $(OBJ)
		@rm -f $(BONUSOBJS)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(SONAME)

re: fclean all

.PHONY: all clean fclean re
