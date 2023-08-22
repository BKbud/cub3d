# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bojung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 17:47:56 by bojung            #+#    #+#              #
#    Updated: 2023/07/26 12:02:56 by bojung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CCFLAGS		= -Wall -Wextra -Werror -g
NAME		= cub3d

MLX_FLAGS	= -framework OpenGL -framework AppKit
RM			= rm -rf

HEADDIR		= ./includes

MLXDIR		= ./minilibx
MLXNAME		= mlx

LIBFTDIR	= ./libft
LIBFTNAME	= ft

MAIN_SRC		= main.c
MAIN_OBJ		= $(MAIN_SRC:.c=.o)

PARSE_SRCDIR	= ./parsing
PARSE_SRCFILES	= map_set.c map_utils.c information_set.c err_handler.c


SRC_SRCS	= $(addprefix $(PARSE_SRCDIR)/, $(PARSE_SRCFILES))

SRC_OBJS	= $(SRC_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CCFLAGS) -I$(HEADDIR) -I$(LIBFTDIR) -I$(MLXDIR) $< -o $@

$(NAME): $(MAIN_OBJ) $(SRC_OBJS)
	$(MAKE) all -C $(LIBFTDIR)
	$(MAKE) all -C $(MLXDIR)
	$(CC) $(CCFLAGS) -L$(LIBFTDIR) -l$(LIBFTNAME) \
		-L$(MLXDIR) -l$(MLXNAME) $(MLX_FLAGS) $^ -o $@

clean:
	$(RM) $(MAIN_OBJ) $(SRC_OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean:
	$(RM) $(MAIN_OBJ) $(SRC_OBJS)
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean

re: fclean all

.PHONY : all clean fclean re
