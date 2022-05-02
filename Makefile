# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 19:32:36 by ccambium          #+#    #+#              #
#    Updated: 2022/05/02 14:43:05 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -fsanitize=address
H_PATH = src
SRCS = src/character.c\
	src/collectible2.c\
	src/collectible.c\
	src/collisions.c\
	src/count.c\
	src/event_handler.c\
	src/exit2.c\
	src/exit.c\
	src/ft_atoi.c\
	src/ft_isdigit.c\
	src/ft_split.c\
	src/ft_strlcpy.c\
	src/ft_strncmp.c\
	src/ft_strtrim.c\
	src/ft_substr.c\
	src/hex_to_int.c\
	src/interactions.c\
	src/map_generation.c\
	src/map_to_tab.c\
	src/render_next_frame.c\
	src/safe_end.c\
	src/so_long.c\
	src/so_long.h\
	src/tileset.c\
	src/tools.c\
	src/verification2.c\
	src/verification.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	libftprintf/libftprintf.a\
	mlx_linux/mlx_linux.a

NAME = so_long

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

TITLE = "\n $(BLUE)███████  ██████          ██       ██████  ███    ██  ██████\n"\
		"$(BLUE)██      ██    ██         ██      ██    ██ ████   ██ ██       \n"\
		"$(BLUE)███████ ██    ██         ██      ██    ██ ██ ██  ██ ██   ███ \n"\
		"$(BLUE)     ██ ██    ██         ██      ██    ██ ██  ██ ██ ██    ██ \n"\
		"$(BLUE)███████  ██████  ███████ ███████  ██████  ██   ████  ██████  \n"\
        "\n\n $(PURPLE)ᐅ $(YELLOW)Making something like $(GREEN)$(NAME) $(YELLOW)or a shitty thing $(RED)(╯°□°)╯︵ ┻━┻ $(RESET)\n\n"                                                   

.SILENT:

all: $(NAME)

fclean:
	rm $(NAME)

clean:
	rm $(NAME)

title:clear
	echo $(TITLE)

clear:
	clear

re: fclean $(NAME)
.PHONY:

$(NAME): title
	$(CC) $(SRCS) $(CFLAGS)
