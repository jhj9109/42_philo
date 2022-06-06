# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 19:13:46 by hyeonjan          #+#    #+#              #
#    Updated: 2022/06/06 14:35:04 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME2 = philo_bonus

CC = cc
# CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

INC_LINK = -I ./includes

AR = ar rcus
RM = rm -f

SRC_DIR = ./srcs/
BNS_DIR = ./bonus/

SRC_FILES = exit.c \
			free.c \
			mutex.c \
			parse.c \
			philo.c \
			thread_func.c \
			utils.c \
			utils2.c

BNS_FILES = exit.c \
			free.c \
			philo.c \
			utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
BNSS = $(addprefix $(BNS_DIR), $(BNS_FILES))

SRC_OBJ = $(SRCS:.c=.o)
BNS_OBJ = $(BNSS:.c=.o)

all: $(NAME)

bonus:
	@make $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(INC_LINK) -o $(NAME) $(SRC_OBJ)

$(NAME2): $(BNS_OBJ)
	$(CC) $(CFLAGS) $(INC_LINK) -o $(NAME2) $(BNS_OBJ)

clean:
	$(RM) $(SRC_OBJ) $(BNS_OBJ)

fclean: 
	make clean
	$(RM) $(NAME) $(NAME2)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
