# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 15:41:28 by ksaetern          #+#    #+#              #
#    Updated: 2017/03/16 18:48:34 by ksaetern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LIBFT	= libft/

FLAG	= -Wall -Wextra -Werror -o

SRCS	= $(LIBFT)libft.a \
	   			main.c \
	   			read.c \
	   			check.c \
	   			store.c \
				solve.c \
				map.c \
				place.c \
	   			
all:	$(NAME)

$(NAME):
		@$(CC) $(FLAG) $(NAME) $(SRCS)

clean:
		rm -f $(OBJS)
fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
