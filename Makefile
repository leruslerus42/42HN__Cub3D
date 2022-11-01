NAME = cub3D

CC = gcc

CFLAGS = -Werror -Wextra -Wall -I minilibx -L opengl -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = 	src/*.c


$(NAME) : ${SRCS}
	make all -C opengl
	make all -C libft
	gcc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C opengl
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C opengl
	make clean -C libft

re : fclean all