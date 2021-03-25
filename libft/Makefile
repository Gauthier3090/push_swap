# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 11:55:40 by gpladet           #+#    #+#              #
#    Updated: 2021/03/25 11:06:12 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_HEADER = ./include/
PATH_SRC = ./srcs/
PATH_OBJ = ./objs/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lm

SRCS = 	ft_memset.c 				\
		ft_bzero.c					\
		ft_memcpy.c					\
 		ft_memccpy.c				\
		ft_memmove.c				\
 		ft_memchr.c					\
		ft_memcmp.c					\
 		ft_strlen.c 				\
		ft_isalpha.c 				\
		ft_isdigit.c				\
 		ft_isalnum.c 				\
		ft_isascii.c 				\
		ft_isprint.c				\
 		ft_toupper.c				\
		ft_tolower.c				\
		ft_strchr.c					\
 		ft_strrchr.c				\
		ft_strncmp.c				\
		ft_strlcpy.c				\
 		ft_strlcat.c				\
		ft_strnstr.c				\
		ft_atoi.c					\
 		ft_calloc.c					\
		ft_strdup.c					\
		ft_substr.c					\
 		ft_strjoin.c				\
		ft_strtrim.c				\
		ft_split.c					\
 		ft_itoa.c					\
		ft_strmapi.c				\
		ft_putchar_fd.c				\
 		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\

SRCSBONUS = ft_lstnew_bonus.c		\
			ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c		\

OBJ_NAME = $(SRCS:.c=.o)
OBJBONUS_NAME = $(SRCSBONUS:.c=.o)
OBJ = $(addprefix $(PATH_OBJ), $(OBJ_NAME))
OBJBONUS = $(addprefix $(PATH_OBJ), $(OBJBONUS_NAME))

YELLOW = \033[01;33m
GREEN = \033[01;32m
RESET = \033[01;0m
INFO = [${YELLOW}INFO${RESET}]
SUCCESS = [${GREEN}OK${RESET}]

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "${INFO} Compilation of $* ${SUCCESS}"

bonus: $(OBJBONUS)
	@ar rc $(NAME) $(OBJBONUS)

clean:
	@/bin/rm -r $(PATH_OBJ) 2> /dev/null || true
	@echo "${INFO} Deleted files and directory"

fclean: clean
	@/bin/rm -r $(NAME) 2> /dev/null || true

re: fclean all

.PHONY: all, clean, fclean, re
