# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 19:13:46 by hyeonjan          #+#    #+#              #
#    Updated: 2022/06/01 19:13:47 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME2 = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_LINK = -I ./includes

AR = ar rcus
RM = rm -f

SRC_DIR = ./srcs/
BNS_DIR = ./bonus/

SRC_FILES = exit.c \
			free.c \
			philo.c

BNS_FILES = exit.c \
			free.c \
			philo.c

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
