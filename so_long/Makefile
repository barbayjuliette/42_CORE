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
LFLAGS = -L${LIBFT} -lft
all: ${NAME}

# %.o: %.c
# 	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) runlibft
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o $(NAME)

# $(NAME): runlibft $(OBJS)
# 		$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

# $(NAME):
# 		@make all -C libft
# 		$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o ${NAME}

runlibft:
	@make all -C libft

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re