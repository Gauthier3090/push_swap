# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <gpladet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 15:34:54 by gpladet           #+#    #+#              #
#    Updated: 2021/03/25 15:26:10 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of binary file
NAME_CHECKER = checker

# Name of directory
PATH_INC_CHECKER = includes_checker/
PATH_SRC_CHECKER = srcs_checker/
PATH_OBJ_CHECKER = objs_checker/
PATH_LIBFT = libft

# List of sources
SRCS_CHECKER = check.c main.c operations.c print.c read.c stack.c utils.c
OBJS_CHECKER = ${addprefix ${PATH_OBJ_CHECKER}, ${SRCS_CHECKER:.c=.o}}
INCS_CHECKER = ${addprefix ${PATH_INC_CHECKER}, header.h}

# Commands of compilation
COMP = gcc
COMP_FLAG = -Wall -Wextra -Werror
COMP_INC = -I ${PATH_INC_CHECKER}

# Others command
RM = /bin/rm

# Color and template code
YELLOW = \033[01;33m
GREEN = \033[01;32m
RESET = \033[01;0m
INFO = [${YELLOW}INFO${RESET}]
SUCCESS = [${GREEN}OK${RESET}]

# Functions
all :	init ${NAME_CHECKER}
		@echo "${INFO} Compilation of ${NAME_CHECKER} ${SUCCESS}"

init :
		@echo "${INFO} Init ${NAME_CHECKER}"
		@${shell mkdir -p ${PATH_OBJ_CHECKER}}
		@make -C ${PATH_LIBFT}

${NAME_CHECKER} : ${OBJS_CHECKER} ${INCS_CHECKER}
		@${CC} ${COMP_FLAG} -o ${NAME_CHECKER} ${OBJS_CHECKER} ${PATH_LIBFT}/libft.a

${PATH_OBJ_CHECKER}%.o : ${PATH_SRC_CHECKER}%.c
		@${COMP} ${COMP_FLAG} ${COMP_INC} -c $< -o $@
		@echo "${INFO} Compilation of $* ${SUCCESS}"

clean :
		@${RM} -rf ${PATH_OBJ_CHECKER}
		@make -C $(PATH_LIBFT) clean;
		@echo "${INFO} Deleted files and directory"

fclean : clean
		@${RM} -rf ${NAME_CHECKER}
		@make -C ${PATH_LIBFT} fclean

re : fclean all

.PHONY : all clean fclean re
