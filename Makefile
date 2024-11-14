GREEN = \033[38;5;2m
YELLOW = \033[38;5;3m
RESET = \033[0m

####################
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_puthex.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
	@ echo "$(GREEN)Completed succifilly$(RESET)"
	@ echo "$()"

$(NAME) : $(OBJ)
	@ ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@ $(CC) $(FLAGS) -c $< -o $@
	@ echo "$(YELLOW)Compiling $< into $@ $(RESET)"
	@ echo "$()"

clean:
	@ rm -f $(OBJ)
	@ echo "$(GREEN)Remove objects... $(OBJ) $(RESET)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(GREEN)Remove $(NAME) $(RESET)"
	@ echo "$()"

re:
	@ $(MAKE) -s fclean && $(MAKE) -s all

.PHONY: all clean fclean re
