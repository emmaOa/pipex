# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 03:34:46 by iouazzan          #+#    #+#              #
#    Updated: 2022/04/07 05:28:33 by iouazzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
    ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
    ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
    ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS=  ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
    ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
    ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=libft.a
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(O_MANDATORY)

bonus: $(O_MANDATORY) $(O_BONUS)

%.o:%.c
	@$(CC) $(FLAGS) $<
	@ar -rc $(NAME) $@

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re: fclean all
