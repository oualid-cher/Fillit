# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 00:13:41 by fkarouac          #+#    #+#              #
#    Updated: 2019/08/17 21:35:46 by fkarouac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_atoi.c\
		ft_isalpha.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_strclr.c\
		ft_strdel.c\
		ft_striter.c\
		ft_strlcat.c\
		ft_strmapi.c\
		ft_strncpy.c\
		ft_strnjoin.c\
		ft_strsplit.c\
		ft_strtrim.c\
		ft_bzero.c\
		ft_isascii.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memdel.c\
		ft_newnode.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_strcat.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strnequ.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_tolower.c\
		ft_addnode.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_memalloc.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putstr.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_strequ.c\
		ft_strjoin.c\
		ft_strmap.c\
		ft_strncmp.c\
		ft_strnew.c\
		ft_strrchr.c\
		ft_strsub.c\
		ft_toupper.c\
		get_next_line.c
OBJ =	ft_atoi.o\
		ft_isalpha.o\
		ft_isprint.o\
		ft_memccpy.o\
		ft_memcpy.o\
		ft_memset.o\
		ft_putchar_fd.o\
		ft_putnbr.o\
		ft_putstr_fd.o\
		ft_strclr.o\
		ft_strdel.o\
		ft_striter.o\
		ft_strlcat.o\
		ft_strmapi.o\
		ft_strncpy.o\
		ft_strnjoin.o\
		ft_strsplit.o\
		ft_strtrim.o\
		ft_bzero.o\
		ft_isascii.o\
		ft_itoa.o\
		ft_memchr.o\
		ft_memdel.o\
		ft_newnode.o\
		ft_putendl.o\
		ft_putnbr_fd.o\
		ft_strcat.o\
		ft_strcmp.o\
		ft_strdup.o\
		ft_striteri.o\
		ft_strlen.o\
		ft_strncat.o\
		ft_strnequ.o\
		ft_strnstr.o\
		ft_strstr.o\
		ft_tolower.o\
		ft_addnode.o\
		ft_isalnum.o\
		ft_isdigit.o\
		ft_memalloc.o\
		ft_memcmp.o\
		ft_memmove.o\
		ft_putchar.o\
		ft_putendl_fd.o\
		ft_putstr.o\
		ft_strchr.o\
		ft_strcpy.o\
		ft_strequ.o\
		ft_strjoin.o\
		ft_strmap.o\
		ft_strncmp.o\
		ft_strnew.o\
		ft_strrchr.o\
		ft_strsub.o\
		ft_toupper.o\
		get_next_line.o
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC) -I .
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
