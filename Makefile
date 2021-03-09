# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 17:33:16 by fgata-va          #+#    #+#              #
#    Updated: 2021/03/09 13:00:00 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_atol.c ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c \
ft_putstr_fd.c  ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_bzero.c \
ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_strchr.c \
ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c \
ft_itoa.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
ft_strtrim.c ft_toupper.c ft_split.c

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

PRINTSRC = ft_printf/ft_chars_strings.c ft_printf/ft_printf.c ft_printf/ft_hexadecimal.c \
ft_printf/ft_printf_utils_1.c ft_printf/ft_integers.c ft_printf/ft_printf_utils_2.c \
ft_printf/ft_pointers.c ft_printf/ft_unsigned.c

PRINTOBJS = $(PRINTSRC:.c=.o)

BONUSOBJS = $(BONUSSRC:.c=.o)

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(PRINTOBJS)
		$(CC) $(CFLAGS) -c -I. -g $(SRC)
		ar rc $(NAME) $(OBJS) $(PRINTOBJS)

$(PRINTOBJS): $(PRINTSRC)
	$(CC) -Ift_printf/ -g -c -o $@ $<

bonus: $(PRINTOBJS)
		$(CC) $(CFLAGS) -c -I. -g $(BONUSSRC) $(SRC)
		ar rc $(NAME) $(OBJ) $(BONUSOBJS) $(PRINTOBJS)

clean: 
		rm -f $(OBJ)
		rm -f $(BONUSOBJS)
		rm -f $(PRINTOBJS)

fclean: clean
		rm -f $(NAME)
		rm -f $(SONAME)

re: fclean all

norm:
	@echo "                                   [Libft norm]"
	@norminette $(SRC) $(BONUSSRC) libft.h
	@echo "                                 [ft_printf norm]"
	@norminette $(PRINTSRC) ft_printf/ft_printf.h

.PHONY: all clean fclean re
