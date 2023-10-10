# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 11:06:32 by jbarbay           #+#    #+#              #
#    Updated: 2023/10/10 11:06:35 by jbarbay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c \
		helpers.c \

CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): $(OBJS)
			make -C libft
			cp libft/libft.a ${NAME}
			$(CC) $(CFLAGS) -c $(SRCS)
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
		make clean -C libft
		${RM} ${OBJS}

fclean: clean
		make fclean -C libft
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
