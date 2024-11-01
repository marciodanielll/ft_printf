NAME=libftprintf.a
CC=-Wall-Wextra -Werror
ESCAPE_SEQUENCE="\033]"
END_SEQUENCE="\007"

all:
	@ echo "${ESCAPE_SEQUENCE}${magenta}${END_SEQUENCE}";

clean:
	@ echo "clean"

fclean: 
	@ echo "fclean"

re: 
	@ echo "re"

.PHONY: all clean fclean re


# Dracula
background="#282A36"
foreground="#F8F8F2"
cursor="#FF79C6"

# Defualt colors
black="#21222C"
red="#FF5555"
green="#50FA7B"
yellow="#F1FA8C"
blue="#BD93F9"
magenta="#FF79C6"
cyan="#8BE9FD"
white="#F8F8F2"

# Bright color
bright_black="#6272A4"
bright_red="#FF6E6E"
bright_green="#69FF94"
bright_yellow="#FFFFA5"
bright_blue="#D6ACFF"
bright_magenta="#FF92DF"
bright_cyan="#A4FFFF"
bright_white="#FFFFFF"



