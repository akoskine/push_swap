# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 22:35:26 by akoskine          #+#    #+#              #
#    Updated: 2024/11/13 13:22:59 by akoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker

SRC_1 = main.c \

SRC_2 =	check_input.c \
		fill_values_indexes.c \
		utils.c \
		sort.c \
		sort_utils.c \
		a_operations.c \
		b_operations.c \
		multiple_operations.c \
		move_sets.c \
		cost_utils.c \
			
BONUS_SRC = checker.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft 

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ}
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME}

bonus: ${BONUS}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
