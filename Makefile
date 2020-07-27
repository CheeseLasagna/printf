# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 19:34:58 by tlavelle          #+#    #+#              #
#    Updated: 2020/07/23 19:35:00 by tlavelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = src/calc_flags.c\
	src/csp.c\
	src/dec_uns_hex.c\
	src/dec_uns_hex2.c\
	src/null.c\
	ft_printf.c

LIBSRC = libft/ft_atoi.c\
	libft/ft_strlen.c\
	libft/ft_itoa.c\
	libft/ft_strdup.c\
	libft/ft_memcpy.c\
	libft/ft_itoaun.c\
	libft/ft_itoahex.c

OBJ = calc_flags.o\
	csp.o\
	dec_uns_hex.o\
	dec_uns_hex2.o\
	null.o\
	ft_atoi.o\
	ft_strlen.o\
	ft_itoa.o\
	ft_strdup.o\
	ft_memcpy.o\
	ft_itoaun.o\
	ft_itoahex.o\
	ft_printf.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC) $(LIBSRC) printf.h libft/libft.h 
	gcc $(FLAGS) -c $(SRC) $(LIBSRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re testing
