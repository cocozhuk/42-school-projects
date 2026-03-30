SERVER = server
CLIENT = client
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f


PRINTF = ft_printf/printf.a
LIBFT = libft/libft.a

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
		@make bonus -C libft
		@make -C ft_printf
		$(CC) $(CFLAGS) server.o $(PRINTF) $(LIBFT) -o $(SERVER)
$(CLIENT): client.o
		@make bonus -C libft
		@make -C ft_printf
		$(CC) $(CFLAGS) client.o $(PRINTF) $(LIBFT) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) server.o client.o
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re