NAME_S = server
NAME_C = client
NAME_SB = server_bonus
NAME_CB = client_bonus

SRCS_S = server.c
SRCS_C = client.c
SRCS_SB = server_bonus.c
SRCS_CB = client_bonus.c
SRCS_U = utils.c
SRCS_UB = utils_bonus.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_SB = $(SRCS_SB:.c=.o)
OBJS_CB = $(SRCS_CB:.c=.o)
OBJS_U = $(SRCS_U:.c=.o)
OBJS_UB = $(SRCS_UB:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME_S) $(NAME_C)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_S): $(OBJS_S) $(OBJS_U)
	$(CC) -o $@ $(OBJS_S) $(OBJS_U)

$(NAME_C): $(OBJS_C) $(OBJS_U)
	$(CC) -o $@ $(OBJS_C) $(OBJS_U)

bonus: $(NAME_SB) $(NAME_CB)

$(NAME_SB): $(OBJS_SB) $(OBJS_UB)
	$(CC) -o $@ $(OBJS_SB) $(OBJS_UB)

$(NAME_CB): $(OBJS_CB) $(OBJS_UB)
	$(CC) -o $@ $(OBJS_CB) $(OBJS_UB)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME_S) $(NAME_SB) $(NAME_C) $(NAME_CB)

re: fclean all

.PHONY: all bonus clean fclean re
