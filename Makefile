VRLIBFT= libft/libft.a
VRPRINTF= printf/libftprintf.a
MANDATORY= pipex.c pipex_utl.c $(VRLIBFT) $(VRPRINTF)
BONUS= pipex_bonus.c pipex_utl_bonus.c get_next_line.c get_next_line_utils.c pipex_heredoc.c $(VRLIBFT) $(VRPRINTF) $(VRGET_NEXT)
CC=cc
FLAGS=-Wall -Werror -Wextra
DEBUG=-fsanitize=address -g
NAME=pipex
PIP=pipex_bonus
O_MANDATORY=$(MANDATORY:%.c=%.o)
O_BONUS=$(BONUS:%.c=%.o)

all: $(NAME)
$(VRLIBFT):
	make re -C libft
$(VRPRINTF):
	make re -C printf
$(NAME): $(VRPRINTF) $(VRLIBFT)
	gcc $(FLAGS) $(MANDATORY) -o $(NAME) -fsanitize=address -g

debug:
	gcc $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME)

bonus: $(PIP)

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