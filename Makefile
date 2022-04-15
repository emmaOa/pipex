VRLIBFT= libft/libft.a
VRPRINTF= printf/libftprintf.a
MANDATORY= pipex.c pipex_utl.c $(VRLIBFT) $(VRPRINTF)
BONUS= pipex_bonus.c $(VRLIBFT) $(VRPRINTF)
CC=cc
FLAGS=-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=pipex
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)
$(VRLIBFT):
	make re -C libft
$(VRPRINTF):
	make re -C printf
$(NAME): $(VRPRINTF) $(VRLIBFT)
	gcc $(FLAGS) $(MANDATORY) $(BONUS) -o  $(NAME)

bonus: $(O_MANDATORY) $(O_BONUS)

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

clean:
	make clean -C libft
	make clean -C printf
	rm -rf *.o

fclean:
	make fclean -C libft
	make fclean -C printf
	rm -rf *.o $(NAME) $(VRPRINTF) $(VRLIBFT)

re: fclean all