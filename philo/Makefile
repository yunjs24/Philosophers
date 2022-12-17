# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 05:31:07 by junsyun           #+#    #+#              #
#    Updated: 2022/12/18 08:16:52 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror #-fsanitize=thread
CFILES			=	init_philo.c \
					check_input_utils.c \
					check_input.c \
					main.c \
					error_handle.c \
					philo.c \
					free_utils.c \
					simulation.c \
					simulation_status.c \
					simulation_utils.c

NAME			= 	philo
OBJS			=	$(CFILES:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $? -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
