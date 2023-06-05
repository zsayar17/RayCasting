CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
ENGINE_MAIN_DIR = $(SRC_DIR)/ENGINE/MAIN
ENGINE_SETELEMENTS_DIR = $(SRC_DIR)/ENGINE/SETELEMENTS
ENGINE_UTILITS_DIR = $(SRC_DIR)/ENGINE/UTILITS
GAME_DIR = $(SRC_DIR)/GAME
GAME_SETUP_DIR = $(GAME_DIR)/SETUP
GAME_UPDATE_DIR = $(GAME_DIR)/UPDATE
MLX_DIR = mlx_mac
NAME = cub3D

SRCS = $(ENGINE_MAIN_DIR)/clear.c \
       $(ENGINE_MAIN_DIR)/init.c \
       $(ENGINE_MAIN_DIR)/main.c \
       $(ENGINE_SETELEMENTS_DIR)/checkelements.c \
       $(ENGINE_SETELEMENTS_DIR)/elements.c \
       $(ENGINE_SETELEMENTS_DIR)/setElements.c \
       $(ENGINE_SETELEMENTS_DIR)/loadAssets.c \
       $(ENGINE_SETELEMENTS_DIR)/splitelements.c \
       $(ENGINE_UTILITS_DIR)/array_process.c \
       $(ENGINE_UTILITS_DIR)/int_prcoess.c \
       $(ENGINE_UTILITS_DIR)/math_process.c \
       $(ENGINE_UTILITS_DIR)/node_process.c \
       $(ENGINE_UTILITS_DIR)/object_circle.c \
       $(ENGINE_UTILITS_DIR)/object_line.c \
       $(ENGINE_UTILITS_DIR)/object_colorize.c \
       $(ENGINE_UTILITS_DIR)/object_process.c \
       $(ENGINE_UTILITS_DIR)/str_get_process.c \
       $(ENGINE_UTILITS_DIR)/str_set_process.c \
       $(GAME_SETUP_DIR)/clearCharacter.c \
       $(GAME_SETUP_DIR)/load_charcter.c \
       $(GAME_SETUP_DIR)/load_map_assets.c \
       $(GAME_SETUP_DIR)/loadScreen.c \
       $(GAME_UPDATE_DIR)/character_move.c \
       $(GAME_UPDATE_DIR)/ray.c \
       $(GAME_UPDATE_DIR)/setScreen.c \
       $(GAME_UPDATE_DIR)/updateMiniMap.c \
       $(GAME_UPDATE_DIR)/updateScreen.c \
       $(GAME_DIR)/game_loop.c \
       $(GAME_DIR)/keyprocess.c \
       $(GAME_DIR)/mouseprocess.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(MLX_DIR)/libmlx.a

re: fclean all
