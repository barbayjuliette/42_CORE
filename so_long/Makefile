SRCS = so_long.c \
		validation.c \
		read_map.c \
		helpers.c \
		end_game.c \
		movements.c \
		validation_2.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
OBJS = ${SRCS:.c=.o}
LIBFT = ./libft
all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) runlibft
	$(CC) $(OBJS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o $(NAME)

runlibft:
	@make all -C libft

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
