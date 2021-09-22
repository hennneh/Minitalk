# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 21:37:05 by gizawahr          #+#    #+#              #
#    Updated: 2021/09/06 19:28:32 by gizawahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

all :
	make -C libft
	gcc -Wall -Wextra -Werror server.c libft/libft.a -o $(NAME1)
	gcc -Wall -Wextra -Werror client.c libft/libft.a -o $(NAME2)

clean :
	make clean -C libft 
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all