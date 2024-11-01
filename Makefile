NAME=libftprintf.a
CC=-Wall -Wextra -Werror

MAGENTA=\033[38;5;13m
BLACK=\033[38;5;0m
RED=\033[38;5;1m
GREEN=\033[38;5;2m
YELLOW=\033[38;5;3m
BLUE=\033[38;5;4m
CYAN=\033[38;5;6m
WHITE=\033[38;5;7m
RESET=\033[0m

all:
	@ echo "$(MAGENTA)all$(RESET)"

clean:
	@ echo "$(GREEN)clean$(RESET)"

fclean: 
	@ echo "$(GREEN)fclean$(RESET)"

re: fclean all
	@ @ echo "$(CYAN)re$(RESET)"

.PHONY: all clean fclean re
MAGENTA