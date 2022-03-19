CC = gcc
CFLAGS =  -Wall -Wextra -Werror -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS = src/character.c\
	src/collectible2.c\
	src/collectible.c\
	src/collisions.c\
	src/count.c\
	src/event_handler.c\
	src/exit2.c\
	src/exit.c\
	src/ft_isdigit.c\
	src/ft_split.c\
	src/ft_strlcpy.c\
	src/ft_strncmp.c\
	src/ft_strtrim.c\
	src/ft_substr.c\
	src/hex_to_int.c\
	src/image.c\
	src/interactions.c\
	src/map_generation.c\
	src/map_to_tab.c\
	src/put_sprite.c\
	src/render_next_frame.c\
	src/safe_end.c\
	src/so_long.c\
	src/so_long.h\
	src/sprite_to_tab.c\
	src/switch_image.c\
	src/tools.c\
	src/verification2.c\
	src/verification.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	libftprintf/libftprintf.a

NAME = so_long

all: $(NAME)

fclean:
	cd libftprintf && $(MAKE) fclean
	cd mlx_linux && $(MAKE) clean
	rm $(NAME)

clean:
	cd libftprintf && $(MAKE) clean
	cd mlx_linux && $(MAKE) clean

.PHONY:

$(NAME): mlx printf
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

mlx:
	cd mlx_linux && $(MAKE)

printf:
	cd libftprintf && $(MAKE)

