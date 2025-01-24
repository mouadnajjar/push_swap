# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 11:40:43 by monajjar          #+#    #+#              #
#    Updated: 2025/01/23 16:32:07 by monajjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

BONUS_NAME := checker

SRCS = helper_functions.c sort_helper.c big_sort.c sort.c stack_utils2.c small_sort.c parsing.c parse.c push_swap.c rules.c rules2.c spliting.c  stack_utils.c  split.c

SRCB = 	bonus/spliting_bonus.c \
		bonus/helper_functions_bonus.c \
		bonus/stack_utils2_bonus.c \
		bonus/parse_bonus.c \
		bonus/rules2_bonus.c \
		bonus/stack_utils_bonus.c \
		bonus/parsing_bonus.c \
		bonus/rules_bonus.c \
		bonus/split_bonus.c \
		bonus/gnl/get_next_line.c \
		bonus/gnl/get_next_line_utils.c \
		bonus/checker_helper.c \
		bonus/checker.c \

OBJS := $(SRCS:.c=.o)

OBJSB := $(SRCB:.c=.o)

CFLAGS := -Wall -Wextra -Werror -g

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(OBJSB) 
		$(CC) $(CFLAGS) $(OBJSB) -o $(BONUS_NAME)
		
bonus: $(BONUS_NAME)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	
re: fclean all

.SECONDARY: $(OBJS)