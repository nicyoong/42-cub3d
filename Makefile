# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 12:53:22 by tching            #+#    #+#              #
#    Updated: 2025/08/10 12:53:25 by tching           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
MKDIR	= mkdir -p
RM		= rm -rf
CC		= cc $(CFLAGS)
CFLAGS	= -Wall -Wextra -Werror -03 #$(DEBUG)
MLXFLAGS = -L(MLX) -lmlx -I$(MLX_DIR) -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

DEBUG	= -g3 -fsanitize=address
INCLUDE	= -I $(INC_DIR)

#PATHS
LIB_DIR		= libft
MLX_DIR		= mlx
PATH_OBJ	= mandatory/obj/
OBJ_DIR		= mandatory/obj
SRC_DIR		= mandatory/src
INC_DIR		= mandatory/inc

SRCS	= $(addprefix $(SRC_DIR)/, \
			close_window.c \
			exit_game.c \
			keypress.c \
			load_map.c \
			main.c \
			pixels.c \
			player.c \
			raycast.c \
			set_params.c \
			setup_game.c \
			start_cubed.c)

OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT)/libft.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_DIR)/libft.a:
	$(MAKE) -C $(LIB_DIR) bonus

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
