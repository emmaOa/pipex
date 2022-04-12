MANDATORY= ft_pointer.c\
	ft_printf.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putnbr_hl.c\
	ft_putnbr_hu.c\
	ft_putnbr_uns.c\
	ft_putstr.c

CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=libftprintf.a
O_MANDATORY=$(MANDATORY:%.c=%.o)

all: $(NAME)

$(NAME): $(O_MANDATORY)

%.o:%.c
	@$(CC) $(FLAGS) $<
	@ar -rc $(NAME) $@

test:
	$(CC) $(MANDATORY)
clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re: fclean all
