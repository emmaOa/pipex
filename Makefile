VRLIBFT= libft/libft.a
VRPRINTF= printf/libftprintf.a
MANDATORY= pipex.c $(VRLIBFT) $(VRPRINTF)
CC=cc
FLAGS=-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=pipex
O_MANDATORY=$(MANDATORY:%.c=%.o)

all: $(NAME)
$(VRLIBFT):
	make re -C libft
$(VRPRINTF):
	make re -C printf
$(NAME): 
	gcc $(FLAGS) $(MANDATORY) -o  $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

clean:
	make clean -C libft
	make clean -C printf
	rm -rf *.o

fclean:
	make fclean -C libft
	make fclean -C printf
	rm -rf *.o $(NAME)

re: fclean all