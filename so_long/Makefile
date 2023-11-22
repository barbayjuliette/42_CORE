SRCS = so_long.c \
		validation.c \
		read_map.c \
		helpers.c \
		end_game.c \
		movements.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
OBJS = ${SRCS:.c=.o}
LIBFT = ./libft
LFLAGS = -L${LIBFT} -lft
all: ${NAME}

# %.o: %.c
# 	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(NAME): runlibft $(OBJS)
# 		$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

runlibft:
	make -C libft --no-print-directory

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re