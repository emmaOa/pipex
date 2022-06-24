# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 18:26:36 by iouazzan          #+#    #+#              #
#    Updated: 2022/06/21 05:01:17 by iouazzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY= pipex.c pipex_utl.c ft_strlen.c ft_putstr_fd.c ft_strjoin.c\
		ft_strncmp.c ft_split.c ft_putchar_fd.c ft_strchr.c
BONUS= pipex_bonus.c pipex_utl_bonus.c get_next_line.c get_next_line_utils.c\
	pipex_heredoc.c main_bonus.c ft_putstr_fd.c ft_strncmp.c\
	ft_split.c ft_putchar_fd.c$(VRGET_NEXT)
CC=cc
FLAGS=#-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=pipex
PIP=pipex_bonus

O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(MANDATORY) -o $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

bonus: $(VRGET_NEXT) $(PIP) -fsanitize=address -g

$(PIP):
	gcc $(FLAGS) $(BONUS) $(DEBUG)  -o $(PIP) -g

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME) $(PIP)

re: fclean all