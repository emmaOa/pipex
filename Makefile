# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 18:26:36 by iouazzan          #+#    #+#              #
#    Updated: 2022/06/18 19:15:57 by iouazzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



VRLIBFT= libft/libft.a
VRPRINTF= printf/libftprintf.a
MANDATORY= pipex.c pipex_utl.c $(VRLIBFT) $(VRPRINTF)
BONUS= pipex_bonus.c pipex_utl_bonus.c get_next_line.c get_next_line_utils.c pipex_heredoc.c main_bonus.c $(VRLIBFT) $(VRPRINTF) $(VRGET_NEXT)
CC=cc
FLAGS=-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=pipex
PIP=pipex_bonus
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)
$(VRLIBFT):
	make -C libft
$(VRPRINTF):
	make -C printf
$(NAME): $(VRPRINTF) $(VRLIBFT)
	gcc $(FLAGS) $(MANDATORY) -o $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

bonus: $(VRPRINTF) $(VRLIBFT) $(PIP)

$(PIP):
	gcc $(FLAGS) $(BONUS) $(DEBUG)  -o $(PIP) -g

clean:
	make clean -C libft
	make clean -C printf
	rm -rf *.o

fclean:
	make fclean -C libft
	make fclean -C printf
	rm -rf *.o $(NAME) $(PIP)

re: fclean all