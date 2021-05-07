# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpladet <gpladet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 15:34:54 by gpladet           #+#    #+#              #
#    Updated: 2021/05/07 22:14:35 by gpladet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of binary file
NAME_CHECKER = checker
NAME_SWAP = push_swap

# Name of directory
PATH_INC_CHECKER = includes_checker/
PATH_SRC_CHECKER = srcs_checker/
PATH_OBJ_CHECKER = objs_checker/

PATH_INC_SWAP = includes_swap/
PATH_SRC_SWAP = srcs_swap/
PATH_OBJ_SWAP = objs_swap/

PATH_LIBFT = libft

# List of sources
SRCS_CHECKER = check.c main.c operations.c print.c read.c stack.c utils.c
OBJS_CHECKER = ${addprefix ${PATH_OBJ_CHECKER}, ${SRCS_CHECKER:.c=.o}}
INCS_CHECKER = ${addprefix ${PATH_INC_CHECKER}, header.h}

SRCS_SWAP = display.c list.c main.c operations.c
OBJS_SWAP = ${addprefix ${PATH_OBJ_SWAP}, ${SRCS_SWAP:.c=.o}}
INCS_SWAP = ${addprefix ${PATH_INC_SWAP}, header.h}

# Commands of compilation
COMP = gcc
COMP_FLAG = -Wall -Wextra -Werror
COMP_INC_CHECKER = -I ${PATH_INC_CHECKER}
COMP_INC_SWAP = -I ${PATH_INC_SWAP}

# Others command
RM = /bin/rm

# Color and template code
YELLOW = \033[01;33m
GREEN = \033[01;32m
RESET = \033[01;0m
INFO = [${YELLOW}INFO${RESET}]
SUCCESS = [${GREEN}OK${RESET}]

# Functions
all :	init ${NAME_CHECKER} ${NAME_SWAP}
		@echo "${INFO} Compilation of ${NAME_CHECKER} ${SUCCESS}"
		@echo "${INFO} Compilation of ${NAME_SWAP} ${SUCCESS}"

init :
		@echo "${INFO} Init ${NAME_CHECKER} ${NAME_SWAP}"
		@make -C ${PATH_LIBFT}
		@${shell mkdir -p ${PATH_OBJ_CHECKER}}
		@${shell mkdir -p ${PATH_OBJ_SWAP}}

${NAME_CHECKER} : ${OBJS_CHECKER} ${INCS_CHECKER}
		@${CC} ${COMP_FLAG} -o ${NAME_CHECKER} ${OBJS_CHECKER} ${PATH_LIBFT}/libft.a

${NAME_SWAP} : ${OBJS_SWAP} ${INCS_SWAP}
		@${CC} ${COMP_FLAG} -o ${NAME_SWAP} ${OBJS_SWAP} ${PATH_LIBFT}/libft.a

${PATH_OBJ_CHECKER}%.o : ${PATH_SRC_CHECKER}%.c
		@${COMP} ${COMP_FLAG} ${COMP_INC_CHECKER} -c $< -o $@
		@echo "${INFO} Compilation of $* ${SUCCESS}"

${PATH_OBJ_SWAP}%.o : ${PATH_SRC_SWAP}%.c
		@${COMP} ${COMP_FLAG} ${COMP_INC_SWAP} -c $< -o $@
		@echo "${INFO} Compilation of $* ${SUCCESS}"

clean :
		@${RM} -rf ${PATH_OBJ_CHECKER}
		@${RM} -rf ${PATH_OBJ_SWAP}
		@make -C $(PATH_LIBFT) clean;
		@echo "${INFO} Deleted files and directory"

fclean : clean
		@${RM} -rf ${NAME_CHECKER}
		@${RM} -rf ${NAME_SWAP}
		@make -C ${PATH_LIBFT} fclean

re : fclean all

.PHONY : all clean fclean re
