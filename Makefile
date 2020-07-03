FLAGS = -Wall -Wextra -Werror -o testing

SRC = src/ft_width.c\
	src/ft_precision.c\
	src/ft_position.c\
	src/ft_spacezero.c\
	src/ft_atoi.c\
	src/dec.c\
	src/ft_strlen.c\
	src/ft_itoa.c\
	src/ft_strdup.c\
	src/ft_memcpy.c\
	src/ft_itoaun.c\
	src/ft_itoahex.c\
	src/csp.c

all:
	gcc $(FLAGS) -g ft_printf.c $(SRC)
