# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:01:19 by jbarbay           #+#    #+#              #
#    Updated: 2023/12/05 17:54:13 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	helpers.c \
	linked_list_helpers.c \
	linked_list_helpers_2.c \
	input_validation.c \
	instructions.c \
	instructions_2.c \
	init_stack.c \
	init_stack_2.c \
	sorting.c \
	push_cheapest.c \
	move_b_to_a.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME):
		@make all bonus -C libft
		$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $<

clean:
		${RM} ${OBJS}
		@make fclean -C libft

fclean: clean
		${RM} ${NAME} ${OBJS}

re: fclean all

.PHONY: all clean fclean re
