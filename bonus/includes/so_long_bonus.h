/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:29:51 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:34:02 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// header includes

# include "../../minilibx-linux/mlx.h"
# include "../../libft/libft.h"
# include "../../libft/ft_printf/includes/ft_printf.h"
# include "../../libft/get_next_line/get_next_line.h"
# include <stddef.h>
# include <X11/X.h>
# include <unistd.h>
# include <fcntl.h>

// return status

# define SUCCESS 0
# define FAILURE 1

// sprite size

# define SPRITE_SIZE 80

// arg error messages

# define E_WRONG_ARG "This program must contain 1 .ber map as parameter."

// map error messages

# define E_MAP_NOT_CLOSED "The map must be closed/surrounded by walls."
# define E_MAP_NOT_RECT "The map is not rectangular."
# define E_FORB_CHARS "The map contains one or more unauthorized characters."
# define E_NO_VALID_PATH "No valid path in the map."
# define E_BAD_PEC_COUNT "The map must contain 1 P, 1 E and at least 1 C."

// open error messages

# define E_BAD_OPEN "The map didn't open properly."

// malloc error messages

# define E_BAD_MALLOC "Malloc failed."

// success messages

# define S_VICTORY "Victory ! You won the game."
# define S_ESCAPE "You have successfully left the game."

// ennemy messages

# define E_ENEMY "You have been killed by an annemy."

typedef struct s_solong
{
	void	*mlx_ptr;
	int		win_w;
	int		win_h;
	void	*win_ptr;
	int		start_pos_x;
	int		start_pos_y;
	int		map_height;
	int		map_width;
	void	*text_1;
	void	*text_0;
	void	*text_c;
	void	*text_e;
	void	*text_pf;
	void	*text_pb;
	void	*text_pl;
	void	*text_pr;
	void	*text_x1;
	void	*text_x2;
	void	*text_x3;
	void	*text_x4;
	void	*text_x5;
	void	*text_x6;
	char	**map;
	char	get_exit;
	int		mov_counter;
	int		c_init_nb;
	int		p_init_nb;
	int		e_init_nb;
	int		p_collected;
	int		c_collected;
	int		e_collected;
	int		o_collected;
	int		c_collected_play;
	int		mov_nb;
}	t_sol;

// mlx

int		on_destroy(t_sol *sol);

// init game

void	init_game(t_sol *sol);
void	init_text(t_sol *sol, int x, int y);
void	assign_assets(t_sol *sol, void *mlx_ptr, int s);
void	assign_assets_ennemies(t_sol *sol, void *mlx_ptr, int s);

// get data

void	get_data(t_sol *sol);
void	get_map_height(t_sol *sol, char *argv1);

// map

int		check_map_format(char *arg);
void	is_valid_map(t_sol *solong, int map_height);
void	free_map(char **map);
void	store_map(t_sol *sol, char *argv1);
void	test_affichage_map(char **map, char *titre);
int		is_valid_path(t_sol *sol);

// errors

void	quit_game(t_sol *sol, char *status_message, int exit_status);
int		clos_win(t_sol *sol);
void	clean(t_sol *sol);
void	display_message(char *status_message, int exit_status);
void	clean_images(t_sol *sol);

// move player

int		move_player(int keysym, t_sol *sol);
void	clean_images_ennemies(t_sol *sol);

#endif
