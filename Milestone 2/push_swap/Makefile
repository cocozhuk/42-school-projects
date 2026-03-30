NAME = push_swap
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

SRCS =  main.c tool_box.c validity_check.c manage_nodes.c algorithm_a.c algorithm_b.c algorithm_push_swap.c\
		functions/push.c functions/re_rotate.c functions/rotate.c functions/swap.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		@make bonus -C libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re