# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 19:12:24 by kshanti           #+#    #+#              #
#    Updated: 2021/07/27 02:36:04 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEAD = ./includes/pipex.h
SRCS = ./srcs/

C_FILE =	$(SRCS)base_utils.c $(SRCS)utils.c $(SRCS)commands.c $(SRCS)init.c \
			$(SRCS)main.c

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
