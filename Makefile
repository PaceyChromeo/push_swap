NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC =	ft_push_swap.c \
		ft_actions.c \
		ft_list.c \
		ft_small_sort.c \
		ft_medium_sort.c \
		ft_large_sort.c \
		ft_large_sort_utils1.c \
		ft_large_sort_utils2.c \
		ft_init.c \
		ft_find.c

OBJ = ${SRC:.c=.o}

LIB = -L./libft -lft

%.o:%.c
	${CC} ${FLAGS} -o $@ -c $<
all: ${NAME}

${NAME}: ${OBJ}
	make -C ./libft
	${CC} -g -o ${NAME} ${LIB} $?

clean:
	rm -rf ${OBJ}
	make clean -C ./libft

fclean: clean
	rm -rf ${NAME}
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean
