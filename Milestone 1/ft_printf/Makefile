NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
RM	= rm -f

SRCS	= ft_printf.c ft_printf_helper.c ft_toolbox.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft 
		cp libft/libft.a $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft fclean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
