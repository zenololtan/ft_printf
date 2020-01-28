# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ztan <ztan@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/06 18:10:05 by ztan           #+#    #+#                 #
#    Updated: 2020/01/28 15:24:33 by ztan          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FUNC = ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_memccpy \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_strchr \
	ft_strdup \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_tolower \
	ft_toupper \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putnbr_fd \
	ft_putendl_fd \
	ft_itoa \
	ft_strmapi \
	ft_split \

SRC2 = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

SRC = $(FUNC:=.c)

OBJ = $(FUNC:=.o)

OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -g $(FLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	gcc -c -g $(FLAGS) $(SRC) $(SRC2)
	ar rc $(NAME) $(OBJ) $(OBJ2)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ) $(OBJ2)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
