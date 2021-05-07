# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkarouac <fkarouac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 21:38:21 by fkarouac          #+#    #+#              #
#    Updated: 2019/10/01 22:41:56 by ahmcherk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =	ft_creatmap.c\
		ft_extractet.c\
		ft_isvalid1.c\
		ft_isvalid2.c\
		ft_solver.c\
		ft_subsolver.c\
		ft_tetrimino.c\
		main.c
FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : 
		make -C libft
		gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a

clean : 
		make clean -C libft
	
fclean :
		make fclean -C libft
		rm -rf $(NAME)

re : fclean all
