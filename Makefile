NAME	=	fractol

SRCS	=	main.c\
			mandelbrote.c\
			julia.c\
			draw.c\
			key_hooks.c\
			mouse_hooks.c\
			burning_ship.c\
			utils.c\
			colors.c

HEADER	=	fractol.h

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

all		: $(NAME)

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -Imlx -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
		@$(MAKE) -C libft
		@$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean	:
		$(MAKE) -C libft clean
		@rm -f $(OBJS)

fclean	:	clean
		$(MAKE) -C libft fclean
		@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
