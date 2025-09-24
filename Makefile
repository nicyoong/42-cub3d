# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 12:53:22 by tching            #+#    #+#              #
#    Updated: 2025/09/24 19:18:56 by nyoong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
BONUS_NAME  = cub3D_bonus
MKDIR	= mkdir -p
RM		= rm -rf
CC		= cc $(CFLAGS)
CFLAGS   = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIB_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -L$(LIB_DIR) -lft

DEBUG	= -g3 -fsanitize=address
INCLUDE	= -I $(INC_DIR)

#PATHS
LIB_DIR		= libft
MLX_DIR		= mlx
PATH_OBJ	= mandatory/obj/
OBJ_DIR		= mandatory/obj
SRC_DIR		= mandatory/src
INC_DIR		= mandatory/inc

BONUS_OBJ_DIR	= bonus/obj
BONUS_SRC_DIR	= bonus/src
BONUS_INC_DIR	= bonus/inc

SRCS	= $(addprefix $(SRC_DIR)/, \
			environment.c \
			exit_game.c \
			free_utils.c \
			keys.c \
			main.c \
			open_file.c \
			params_utils.c \
			player.c \
			player_utils.c \
			raycast.c \
			resize_map.c \
			set_params.c \
			setup_game.c \
			validate_file.c \
			validate_map.c \
			walls.c)

BONUS_SRCS = $(addprefix $(BONUS_SRC_DIR)/, \
			cleanup_doors.c \
			doors.c \
			environment.c \
			exit_game.c \
			free_utils.c \
			keys.c \
			main.c \
			mouse.c \
			open_file.c \
			params_utils.c \
			player.c \
			player_utils.c \
			raycast.c \
			resize_map.c \
			set_params.c \
			setup_game.c \
			validate_file.c \
			validate_map.c \
			walls.c)

OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(LIB_DIR)/libft.a $(MLX_DIR)/libmlx.a $(NAME)

$(LIB_DIR)/libft.a:
	$(MAKE) -C $(LIB_DIR) bonus

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIB_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: $(BONUS_OBJS) $(LIB_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) -I$(BONUS_INC_DIR) $^ -o $(BONUS_NAME) $(MLXFLAGS)

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -I$(BONUS_INC_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	$(MKDIR) $(BONUS_OBJ_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
