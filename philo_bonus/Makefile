# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 19:13:46 by hyeonjan          #+#    #+#              #
#    Updated: 2022/06/12 16:40:04 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_LINK = -I ./includes

AR = ar rcus
RM = rm -f

BNS_DIR = ./srcs/

BNS_FILES = achieve_func.c \
			child_proc.c \
			exit.c \
			free.c \
			handle_fork.c \
			parse.c \
			philo_bonus.c \
			semaphore.c \
			thread_func.c \
			utils.c \
			utils2.c

BNSS = $(addprefix $(BNS_DIR), $(BNS_FILES))

BNS_OBJ = $(BNSS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(NAME): $(BNS_OBJ)
	$(CC) $(CFLAGS) $(INC_LINK) -o $(NAME) $(BNS_OBJ)

clean:
	$(RM) $(BNS_OBJ)

fclean: 
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
