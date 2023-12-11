SRCS = philosophers.c \
			helpers.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
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
