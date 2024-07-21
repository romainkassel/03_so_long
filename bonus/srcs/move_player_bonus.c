/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:45:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:55:54 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_sol *sol)
{
	int	x;
	int	y;

	x = sol->start_pos_x * SPRITE_SIZE;
	y = sol->start_pos_y * SPRITE_SIZE;
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pb, x, y);
	if (sol->map[sol->start_pos_y - 1][sol->start_pos_x] == 'X')
		quit_game(sol, E_ENEMY, FAILURE);
	if ((sol->map[sol->start_pos_y - 1][sol->start_pos_x] == 'E'
		&& sol->c_collected_play == sol->c_collected)
		|| (sol->map[sol->start_pos_y - 1][sol->start_pos_x] == 'C')
		|| (sol->map[sol->start_pos_y - 1][sol->start_pos_x] == '0'))
	{
		if (sol->map[sol->start_pos_y - 1][sol->start_pos_x] == 'C')
			sol->c_collected_play++;
		sol->get_exit = sol->map[sol->start_pos_y - 1][sol->start_pos_x];
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x] = '0';
		y -= 80;
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pb, x, y);
		sol->map[sol->start_pos_y - 1][sol->start_pos_x] = 'P';
		sol->mov_counter++;
		sol->start_pos_y--;
	}
}

void	move_left(t_sol *sol)
{
	int	x;
	int	y;

	x = sol->start_pos_x * SPRITE_SIZE;
	y = sol->start_pos_y * SPRITE_SIZE;
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pl, x, y);
	if (sol->map[sol->start_pos_y][sol->start_pos_x - 1] == 'X')
		quit_game(sol, E_ENEMY, FAILURE);
	if ((sol->map[sol->start_pos_y][sol->start_pos_x - 1] == 'E'
		&& sol->c_collected_play == sol->c_collected)
		|| (sol->map[sol->start_pos_y][sol->start_pos_x - 1] == 'C')
		|| (sol->map[sol->start_pos_y][sol->start_pos_x - 1] == '0'))
	{
		if (sol->map[sol->start_pos_y][sol->start_pos_x - 1] == 'C')
			sol->c_collected_play++;
		sol->get_exit = sol->map[sol->start_pos_y][sol->start_pos_x - 1];
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x] = '0';
		x -= 80;
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pl, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x - 1] = 'P';
		sol->mov_counter++;
		sol->start_pos_x--;
	}
}

void	move_down(t_sol *sol)
{
	int	x;
	int	y;

	x = sol->start_pos_x * SPRITE_SIZE;
	y = sol->start_pos_y * SPRITE_SIZE;
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pf, x, y);
	if (sol->map[sol->start_pos_y + 1][sol->start_pos_x] == 'X')
		quit_game(sol, E_ENEMY, FAILURE);
	if ((sol->map[sol->start_pos_y + 1][sol->start_pos_x] == 'E'
		&& sol->c_collected_play == sol->c_collected)
		|| (sol->map[sol->start_pos_y + 1][sol->start_pos_x] == 'C')
		|| (sol->map[sol->start_pos_y + 1][sol->start_pos_x] == '0'))
	{
		if (sol->map[sol->start_pos_y + 1][sol->start_pos_x] == 'C')
			sol->c_collected_play++;
		sol->get_exit = sol->map[sol->start_pos_y + 1][sol->start_pos_x];
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x] = '0';
		y += 80;
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pf, x, y);
		sol->map[sol->start_pos_y + 1][sol->start_pos_x] = 'P';
		sol->mov_counter++;
		sol->start_pos_y++;
	}
}

void	move_right(t_sol *sol)
{
	int	x;
	int	y;

	x = sol->start_pos_x * SPRITE_SIZE;
	y = sol->start_pos_y * SPRITE_SIZE;
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pr, x, y);
	if (sol->map[sol->start_pos_y][sol->start_pos_x + 1] == 'X')
		quit_game(sol, E_ENEMY, FAILURE);
	if ((sol->map[sol->start_pos_y][sol->start_pos_x + 1] == 'E'
		&& sol->c_collected_play == sol->c_collected)
		|| (sol->map[sol->start_pos_y][sol->start_pos_x + 1] == 'C')
		|| (sol->map[sol->start_pos_y][sol->start_pos_x + 1] == '0'))
	{
		if (sol->map[sol->start_pos_y][sol->start_pos_x + 1] == 'C')
			sol->c_collected_play++;
		sol->get_exit = sol->map[sol->start_pos_y][sol->start_pos_x + 1];
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x] = '0';
		x += 80;
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pr, x, y);
		sol->map[sol->start_pos_y][sol->start_pos_x + 1] = 'P';
		sol->mov_counter++;
		sol->start_pos_x++;
	}
}

int	move_player(int keysym, t_sol *sol)
{
	char	*count;

	count = NULL;
	if (keysym == 65307)
		quit_game(sol, S_ESCAPE, SUCCESS);
	sol->mov_counter = 0;
	sol->get_exit = '\0';
	if (keysym == 119 || keysym == 65362)
		move_up(sol);
	else if (keysym == 97 || keysym == 65361)
		move_left(sol);
	else if (keysym == 115 || keysym == 65364)
		move_down(sol);
	else if (keysym == 100 || keysym == 65363)
		move_right(sol);
	if (sol->mov_counter == 1)
		sol->mov_nb++;
	count = ft_itoa(sol->mov_nb);
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, 0, 0);
	mlx_string_put(sol->mlx_ptr, sol->win_ptr, 30, 30, 0xFFFFFF, count);
	free(count);
	if (sol->get_exit == 'E')
		(init_text(sol, 0, 0), quit_game(sol, S_VICTORY, SUCCESS));
	return (SUCCESS);
}
