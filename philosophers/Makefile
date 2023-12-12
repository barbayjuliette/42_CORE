SRCS = philosophers.c \
			helpers.c \
			threads.c \
			actions.c

CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
