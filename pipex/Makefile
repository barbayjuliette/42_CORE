SRCS = main.c \

CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = pipex
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME):
			@make all -C libft
			$(CC) $(SRCS) -L./libft -lft -o ${NAME}

%.o: %.c
	${CC} -c $<

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
