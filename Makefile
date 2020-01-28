# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ztan <ztan@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/09 14:26:49 by ztan           #+#    #+#                 #
#    Updated: 2020/01/28 16:28:08 by ztan          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_DIR = ./obj/

OBJ_FILES = format_check.o \
			ft_printf.o \
			utils.o \
			print_int.o \
			print_str.o \
			print_char.o \
			print_unint.o \
			print_hex.o \
			print_pointer.o \
			itoa_base16.o

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRCS_DIR = ./srcs/

INC = libftprintf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): obj_dir $(OBJ)
	cd libft/ && $(MAKE)
	cp libft/libft.a ./$(NAME)
	ar rcs $@ $(OBJ)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) -o $@ -c $(FLAGS) -I $(INC) $<

obj_dir:
	/bin/mkdir -p obj

clean:
	cd libft/ && $(MAKE) fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
