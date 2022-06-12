# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 19:13:46 by hyeonjan          #+#    #+#              #
#    Updated: 2022/06/12 16:36:22 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_LINK = -I ./includes

AR = ar rcus
RM = rm -f

SRC_DIR = ./srcs/

SRC_FILES = exit.c \
			free.c \
			handle_fork.c \
			mutex.c \
			parse.c \
			philo.c \
			thread_func.c \
			utils.c \
			utils2.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(INC_LINK) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: 
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
