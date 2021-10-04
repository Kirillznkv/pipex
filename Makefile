# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 19:12:24 by kshanti           #+#    #+#              #
#    Updated: 2021/10/04 20:08:52 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEAD = ./includes/pipex.h
SRCS = ./srcs/
UTILS = ./srcs/utils/
GNL = ./get_next_line/

C_FILE =	$(UTILS)base_utils.c $(SRCS)commands.c $(UTILS)utils.c $(SRCS)init.c \
			$(SRCS)main.c $(UTILS)ft_split.c $(SRCS)find_exec.c \
			$(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(UTILS)base_utils_two.c

C_BONUS =	$(UTILS)base_utils.c $(SRCS)commands.c $(UTILS)utils.c $(SRCS)init_bonus.c \
			$(SRCS)main_bonus.c $(UTILS)ft_split.c $(SRCS)find_exec.c \
			$(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(UTILS)base_utils_two.c

ifdef ADD_BONUS
	O_FILE = $(C_BONUS:.c=.o)
else
	O_FILE = $(C_FILE:.c=.o)
endif

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c -Wall -Wextra -Werror $< -o $@

bonus:
	@$(MAKE) ADD_BONUS=1 all

clean:
	@rm -f $(O_FILE) $(SRCS)init_bonus.o $(SRCS)main_bonus.o .shell_file

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
