# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 21:49:40 by ksuzuki           #+#    #+#              #
#    Updated: 2021/05/05 09:32:05 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= checker

SRCS = ./check_argment.c\
		./check_int.c\
		./command_tool1.c\
		./command_tool2.c\
		./ft_isdigit.c\
		./ft_malloc.c\
		./ft_strchar.c\
		./ft_strcpy.c\
		./main.c\
		./managing_list.c\
		./push_and_pop_list.c\
		./quick_sort.c\
		./read_input.c\
		./rotate_list.c\
		./swap_list.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
