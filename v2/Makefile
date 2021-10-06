all:
	gcc -Wall -Wextra -Werror server.c utils.c -o server
	gcc -Wall -Wextra -Werror client.c utils.c -o client

clean:
	rm -rf client.o server.o

fclean: clean
	rm -rf server client

re: fclean all
