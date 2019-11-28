# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ztan <ztan@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 14:26:49 by ztan           #+#    #+#                 #
#    Updated: 2019/11/27 16:22:45 by ztan          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FUNC = ft_printf ft_putchar ft_putnbr ft_putpointer ft_putstr

SRC = $(FUNC:=.c)

OBJ = $(FUNC:=.o)

$(NAME):
	gcc -c $(FLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -rf $(OBJ) $(OBJ2)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
