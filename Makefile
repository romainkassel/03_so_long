NAME = so_long

SRCS = ./srcs/
SRCS_BONUS = ./bonus/srcs/

WFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lminilibx-linux -lmlx
LIBFT_FLAGS = -Llibft -lft

LIBFT_INCLUDES = -Ilibft
SO_LONG_INCLUDES = -Iincludes
SO_LONG_INCLUDES_BONUS = -Ibonus/includes
FT_PRINTF_INCLUDES = -Ilibft/ft_printf/includes
MLX_INCLUDES = -Iminilibx-linux

ifeq ($(shell uname), Linux)
	X11_INCLUDES = -I/usr/include
	PATH_X11 = -L/usr/lib/X11
else
	X11_INCLUDES = -I/opt/X11/include
	PATH_X11 = -L/usr/X11/lib
	X11_FLAGS = -framework OpenGL -framework AppKit
	
endif

X11_FLAGS += $(PATH_X11) -lXext -lX11

CFILES = $(SRCS)so_long.c $(SRCS)is_valid_map.c $(SRCS)quit_game.c $(SRCS)get_data.c $(SRCS)map.c $(SRCS)init_game.c $(SRCS)move_player.c
OFILES = $(CFILES:.c=.o)

CFILES_BONUS = $(SRCS_BONUS)so_long_bonus.c $(SRCS_BONUS)is_valid_map_bonus.c $(SRCS_BONUS)quit_game_bonus.c $(SRCS_BONUS)get_data_bonus.c $(SRCS_BONUS)map_bonus.c $(SRCS_BONUS)init_game_bonus.c $(SRCS_BONUS)manage_assets_bonus.c $(SRCS_BONUS)move_player_bonus.c
OFILES_BONUS = $(CFILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	cd libft && $(MAKE)
	$(CC) $(WFLAGS) -o $(NAME) $(OFILES) $(MLX_FLAGS) $(X11_FLAGS) $(LIBFT_FLAGS)

%.o: %.c $(SO_LONG_INCLUDES)
	$(CC) $(WFLAGS) -c $(CFILES) $(MLX_INCLUDES) $(X11_INCLUDES) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

$(SRCS_BONUS)%.o: $(SRCS_BONUS)%.c $(SO_LONG_INCLUDES_BONUS)
	$(CC) $(WFLAGS) -c $(CFILES) $(MLX_INCLUDES) $(X11_INCLUDES) $(LIBFT_INCLUDES) $(FT_PRINTF_INCLUDES)

bonus: fclean $(OFILES_BONUS)
	cd libft && $(MAKE)
	$(CC) $(WFLAGS) -o $(NAME) $(OFILES_BONUS) $(MLX_FLAGS) $(X11_FLAGS) $(LIBFT_FLAGS)

clean: 
	rm -f $(OFILES)
	rm -f $(OFILES_BONUS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft && rm -f libft.a

re: fclean all

.PHONY: all clean fclean re bonus
