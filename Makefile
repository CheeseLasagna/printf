NAME = printf.a

FLAGS = -Wall -Wextra -Werror

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

OBJ = calc_flags.o\
	csp.o\
	duxX.o\
	ft_atoi.o\
	ft_strlen.o\
	ft_itoa.o\
	ft_strdup.o\
	ft_memcpy.o\
	ft_itoaun.o\
	ft_itoahex.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC) printf.h
	gcc $(FLAGS) -c $(SRC) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re testing
testing:
	gcc $(FLAGS) -o testing -g main.c ft_printf.c $(SRC)

