CC := cc
NAME := push_swap
FLAGS := -Wall -Werror -Wextra
LIB_DIR := Libft
LIB_NAME := libft.a
FILES := error_handling.c prep_nodes_a.c prep_nodes_b.c \
		push_swap.c push.c rev_rotate.c \
		rotate.c sort_stacks.c sort_three.c \
		sort_utils.c stack_initialization.c swap.c \
		utils.c
OBJ_FILES := ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${LIB_NAME}${OBJ_FILES}
	${CC} ${FLAGS} ${FILES} -I. ${LIB_DIR}/${LIB_NAME} -o ${NAME}

${LIB_NAME}:
	${MAKE} -C Libft

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C Libft

re: clean fclean all
	clear

norm:
	@norminette -R CheckDefine *.h
	@norminette -R CheckForbiddenSourceHeader *.c */*.c

test:
	${CC} ${FILES} -I. ${LIB_DIR}/${LIB_NAME} -o ${NAME}
	./push_swap 2 1 3 6 5 8

.PHONY: all clean fclean re norm