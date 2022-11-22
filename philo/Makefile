# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 05:31:07 by junsyun           #+#    #+#              #
#    Updated: 2022/11/23 06:22:15 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project File

NAME 	=	philo

INC		=	includes/philo.h

SRC		=	src/philo.c \
			src/init.c	\
			src/actions.c 

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -pthread

RM		=	rm -rf

OBJS	=	$(SRCS:.c=.o)


# Project Path of sources, includes, library
LIBFT_DIR		= ./include/libft/

# Libft Library Archive file

LIBFT_DIR		= $(LIBFT_DIR)/libft.a

# Header Path
INC		=	./includes/

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all:	$(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean
		all


.PHONY: all clean fclean re