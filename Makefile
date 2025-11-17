# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME        = cub3D

# ---------------------------- SOURCE & OBJECT FILES ---------------------------
SRCS        = src/main.c src/validation.c src/floodfill.c src/ft_exit.c \
              src/map_validation.c src/set_player_pos.c src/init.c src/raycasting.c \
			  src/line_validation.c src/check_filled_elements.c src/check_color_elements.c \
			  src/moving.c src/run_hooks.c src/draw_textures.c src/copy_map.c

OFILES      = $(SRCS:src/%.c=obj/%.o)

# ---------------------------- LIBRARIES & PATHS -------------------------------
LIB_PATH    = ./libft
MLX_PATH    = ./MLX42/MLX42

MLX         = -L$(MLX_PATH)/build -lmlx42
LDFLAGS     = -L$(LIB_PATH) -lft
MLX_FLAGS   = -lglfw -ldl -lm -pthread

# ---------------------------- COMPILER SETTINGS -------------------------------
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I$(LIB_PATH) -I$(MLX_PATH)/include

# ---------------------------- BUILD RULES -------------------------------------
all: mlx42 libft $(NAME)

libft:
	$(MAKE) -C $(LIB_PATH)

mlx42:
	cmake -B $(MLX_PATH)/build $(MLX_PATH)
	cmake --build $(MLX_PATH)/build -j4

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(MLX) $(LDFLAGS) $(MLX_FLAGS) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---------------------------- CLEANING RULES ----------------------------------
clean:
	$(MAKE) -C $(LIB_PATH) clean
	rm -f $(OFILES)
	rm -rf obj

fclean: clean
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(MLX_PATH)/build
	rm -f $(NAME)

re: fclean all

# ---------------------------- PHONY TARGETS -----------------------------------
.PHONY: all clean fclean re libft mlx42
