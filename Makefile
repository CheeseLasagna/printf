NAME = printf.a

FLAGS = -Wall -Wextra -Werror -o testing

SRC = src/calc_flags.c\
	src/csp.c\
	src/duxX.c\
	src/ft_atoi.c\
	src/ft_strlen.c\
	src/ft_itoa.c\
	src/ft_strdup.c\
	src/ft_memcpy.c\
	src/ft_itoaun.c\
	src/ft_itoahex.c

OBJ = $(SRC: .c=.o)

all:
	gcc $(FLAGS) -g main.c ft_printf.c $(SRC)
