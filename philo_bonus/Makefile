# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 04:13:59 by junsyun           #+#    #+#              #
#    Updated: 2023/01/24 08:06:04 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
CFILES			=	check_input_utils_bonus.c \
					check_input_bonus.c \
					main_bonus.c \
					error_handle_bonus.c \
					philo_bonus.c \
					init_data_bonus.c \
					free_box_bonus.c \
					moniter_bonus.c \
					simulation_bonus.c \
					simulation_status_bonus.c \
					simulation_utils_bonus.c

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
