# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 21:49:40 by ksuzuki           #+#    #+#              #
#    Updated: 2021/05/05 09:33:12 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

SRCS = ./bfs.c\
		./check_argment.c\
		./check_int.c\
		./command_tool1.c\
		./command_tool2.c\
		./command_tool3.c\
		./dcl_set_tool1.c\
		./dcl_set_tool2.c\
		./dcl_set_tool3.c\
		./ft_isdigit.c\
		./ft_malloc.c\
		./ft_strchar.c\
		./ft_strcpy.c\
		./ft_strlen.c\
		./list_tool.c\
		./main.c\
		./managing_list.c\
		./push_and_pop_list.c\
		./qs.c\
		./qs_bfs.c\
		./qs_tool1.c\
		./qs_tool2.c\
		./quick_sort.c\
		./quick_sort2.c\
		./rotate_list.c\
		./swap_bfs.c\
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
