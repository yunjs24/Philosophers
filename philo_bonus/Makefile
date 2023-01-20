# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 04:13:59 by junsyun           #+#    #+#              #
#    Updated: 2023/01/18 18:04:37 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror -fsanitize=thread
CFILES			=	check_input_utils.c \
					check_input.c \
					main.c \
					error_handle.c \
					philo_bonus.c \
					init_data.c \
					free_box.c \
					monitor.c \
					simulation.c \
					simulation_status.c \
					simulation_utils.c

NAME			= 	philo_bonus
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
