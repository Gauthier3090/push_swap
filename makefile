# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 15:34:54 by gpladet           #+#    #+#              #
#    Updated: 2021/03/25 14:00:42 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of binary file
NAME = checker

# Name of directory
PATH_INC = includes/
PATH_SRC = srcs/
PATH_OBJ = objs/
PATH_LIBFT = libft

# List of sources
SRCS = check.c main.c operations.c print.c read.c stack.c utils.c
OBJS = ${addprefix ${PATH_OBJ}, ${SRCS:.c=.o}}
INCS = ${addprefix ${PATH_INC}, header.h}

# Commands of compilation
COMP = gcc
COMP_FLAG = -Wall -Wextra -Werror
COMP_INC = -I ${PATH_INC}

# Others command
RM = /bin/rm

# Color and template code
YELLOW = \033[01;33m
GREEN = \033[01;32m
RESET = \033[01;0m
INFO = [${YELLOW}INFO${RESET}]
SUCCESS = [${GREEN}OK${RESET}]

# Functions
all :	init ${NAME}
		@echo "${INFO} Compilation of ${NAME} ${SUCCESS}"

init :
		@echo "${INFO} Init ${NAME}"
		@${shell mkdir -p ${PATH_OBJ}}
		@make -C ${PATH_LIBFT}

${NAME} : ${OBJS} ${INCS}
		@${CC} ${COMP_FLAG} -o ${NAME} ${OBJS} ${PATH_LIBFT}/libft.a

${PATH_OBJ}%.o : ${PATH_SRC}%.c
		@${COMP} ${COMP_FLAG} ${COMP_INC} -c $< -o $@
		@echo "${INFO} Compilation of $* ${SUCCESS}"

clean :
		@${RM} -rf ${PATH_OBJ}
		@make -C $(PATH_LIBFT) clean;
		@echo "${INFO} Deleted files and directory"

fclean : clean
		@${RM} -rf ${NAME}
		@make -C ${PATH_LIBFT} fclean

re : fclean all

.PHONY : all clean fclean re
