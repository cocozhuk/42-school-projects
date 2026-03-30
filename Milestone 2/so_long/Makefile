NAME	= so_long
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lz
RM	= rm -f

SRCS	= toolbox.c main.c map_parsing.c map_rules_2.c map_rules.c game_image.c game_movement.c GNL/get_next_line.c GNL/get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/printf.a

all: $(NAME)

$(NAME): $(OBJS)
		@make bonus -C libft
		@make -C ft_printf
		@make -C mlx
		$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean
	make -C mlx clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C ft_printf fclean
	make -C mlx clean

re: fclean all

.PHONY: all clean fclean re
