# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 13:35:33 by hanryu            #+#    #+#              #
#    Updated: 2023/08/25 15:08:58 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADDIR = ./includes

MAIN_SRC = main.c

PARSE_SRCDIR = ./parsing
PARSE_SRCS = map_set.c map_utils.c information_set.c err_handler.c get_next_line.c

RAYCAST_SRCDIR = ./raycast
RAYCAST_SRCS = raycast.c draw.c raycast_single_step_x.c raycast_single_step_y.c texture.c \
				door.c

UTILS_SRCDIR = ./utils
UTILS_SRCS = vec.c utils.c

PLAYER_SRCDIR = ./player
PLAYER_SRCS = init_player.c player.c

MINIMAP_SRCDIR = ./minimap
MINIMAP_SRCS = minimap.c

SRCS =	$(MAIN_SRC)\
		$(addprefix $(PARSE_SRCDIR)/, $(PARSE_SRCS))\
		$(addprefix $(RAYCAST_SRCDIR)/, $(RAYCAST_SRCS))\
		$(addprefix $(UTILS_SRCDIR)/, $(UTILS_SRCS))\
		$(addprefix $(PLAYER_SRCDIR)/, $(PLAYER_SRCS))\
		$(addprefix $(MINIMAP_SRCDIR)/, $(MINIMAP_SRCS))

OBJS = $(SRCS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

MLXNAME = mlx
MLXDIR = ./minilibx_mms_20210621
MLX = libmlx.dylib

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	make -C $(MLXDIR) all
	cp $(MLXDIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(LIBNAME) -L$(MLXDIR) -l$(MLXNAME) \
		-framework OpenGL -framework AppKit $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADDIR) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@

all : $(NAME)

clean :
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(NAME) $(MLX)

re : fclean all

.PHONY : all clean fclean re