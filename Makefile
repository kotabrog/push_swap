# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 22:13:32 by ksuzuki           #+#    #+#              #
#    Updated: 2021/05/04 22:16:50 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CHECKER_DIR = ./checker_src
PUSH_SWAP_DIR = ./push_swap_src

all:
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(PUSH_SWAP) ./
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(PUSH_SWAP)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all re fclean clean
