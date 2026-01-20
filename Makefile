# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 11:49:40 by anasinda          #+#    #+#              #
#    Updated: 2026/01/20 11:59:24 by anasinda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = program
NAME_BONUS = program_bonus

MAIN = src/main.c
MAIN_BONUS = src_bonus/main_bonus.c

SRC = src/get_next_line.c src/get_next_line_utils.c
SRC_BONUS = src_bonus/get_next_line_bonus.c src_bonus/get_next_line_utils_bonus.c

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all

$(NAME): $(SRC)
	$(CC) $(C_FLAGS) $(SRC) $(MAIN) -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS) $(MAIN_BONUS)
	$(CC) $(C_FLAGS) $(SRC_BONUS) $(MAIN_BONUS) -o $(NAME_BONUS)
