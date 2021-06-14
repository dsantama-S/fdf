LIB		=	fdf.h
SRCS	=	main.c analyze_file.c get_next_line.c algoritmo.c
			
OBJS	=	$(SRCS:.c=.o)
NAME	=	fdf
CFLAGS	=	-Wall -Werror -Wextra
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz libft.a
MLX		=	libmlx.dylib

$(NAME):	$(MLX) $(OBJS) _libft
			@gcc -o $(NAME) $(OBJS) ${MLX} $(LIBS)
$(MLX):
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .
.c.o:
			gcc -g -O3 -Wall -Werror -Wextra -I. -c $< -o $(<:.c=.o)

_libft:
			@make -C libft
			mv ./libft/libft.a ./

all:		$(NAME)

clean:
			rm -f $(OBJS) $(LIBS) $(MLX)
			@make clean -C libft

fclean:		clean
			rm -f $(NAME) $(LIBS) $(MLX)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re