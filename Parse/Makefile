# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 10:52:24 by zmeribaa          #+#    #+#              #
#    Updated: 2022/04/08 21:55:37 by zmeribaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= mini
CC		= gcc
FLAGS	= -Wall -Wextra -Werror 

SRCS	= *.c

OBJS	= $(SRCS:.c=.o)

%.o:%.c ,%.h
	$(CC) $(FLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:  clean
	rm -rf $(NAME)

re: fclean all