# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 05:31:07 by junsyun           #+#    #+#              #
#    Updated: 2022/12/09 09:56:28 by junsyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror

# Mandatory
SRCS		=	./src/philo.c \
				./src/init.c \
				./src/actions.c
			
OBJS	=	$(SRCS:.c=.o)


LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

NAME			=	philo

.PHONY: all
all:
	make $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $? -o $@	

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAG) $(LIBFT) $^ -o $@

.PHONY: clean
clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)


.PHONY: fclean
fclean:
	@make -C $(LIBFT_DIR) fclean
	make clean
	rm -f $(NAME)


.PHONY: re
re:
	make fclean
	make all

# # Project File

# NAME 	=	philo

# INC		=	includes/philo.h \

# SRC		=	src/philo.c \
# 			src/init.c	\
# 			src/actions.c 

# CC		=	gcc

# FLAGS	=	-Wall -Wextra -Werror -pthread

# RM		=	rm -rf

# OBJS	=	$(SRC:.c=.o)


# # Project Path of sources, includes, library
# LIBFT_DIR		= ./include/libft/

# # Libft Library Archive file

# LIBFT		= $(LIBFT_DIR)/libft.a

# # Header Path
# INC		=	./includes/

# $(NAME): $(OBJS)
# 		@make -C $(LIBFT_DIR)
# 		$(CC) $(FLAGS) $(SRC) $(LIBFT) $^ -o $@


# all:
# 	make $(NAME)
# # all:	$(NAME) $(OBJS) $(INC)

# %.o: %.c $(INC)
# 		$(CC) $(FLAGS) -c $< -o $@

# clean:
# 		@make -C $(LIBFT_DIR) clean
# 		$(RM) $(OBJS)

# fclean:
# 		clean
# 		@make -C $(LIBFT_DIR) fclean
# 		$(RM) $(NAME)

# re:		fclean
# 		all


# .PHONY: all clean fclean re