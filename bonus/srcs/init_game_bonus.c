/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:51:10 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:30:13 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_assets(t_sol *sol)
{
	sol->text_1 = NULL;
	sol->text_0 = NULL;
	sol->text_c = NULL;
	sol->text_e = NULL;
	sol->text_pf = NULL;
	sol->text_pb = NULL;
	sol->text_pl = NULL;
	sol->text_pr = NULL;
	sol->text_x1 = NULL;
	sol->text_x2 = NULL;
	sol->text_x3 = NULL;
	sol->text_x4 = NULL;
	sol->text_x5 = NULL;
	sol->text_x6 = NULL;
}

void	display_text(t_sol *sol, char curr_char, int x, int y)
{
	if (curr_char == '1')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_1, x, y);
	if (curr_char == '0')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, x, y);
	if (curr_char == 'C')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_c, x, y);
	if (curr_char == 'E')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_e, x, y);
	if (curr_char == 'P')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_pf, x, y);
	if (curr_char == 'X')
		mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_x4, x, y);
}

void	init_text(t_sol *sol, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (sol->map[i])
	{
		j = 0;
		while (sol->map[i][j])
		{
			x = j * SPRITE_SIZE;
			y = i * SPRITE_SIZE;
			if (!(i == 0 && j == 0))
				display_text(sol, sol->map[i][j], x, y);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(sol->mlx_ptr, sol->win_ptr, sol->text_0, 0, 0);
	mlx_string_put(sol->mlx_ptr, sol->win_ptr, 30, 30, 0xFFFFFF, "0");
}

void	init_game(t_sol *sol)
{
	sol->mlx_ptr = mlx_init();
	if (!sol->mlx_ptr)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->win_ptr = mlx_new_window(sol->mlx_ptr, sol->win_w, sol->win_h, "SOL");
	if (!sol->win_ptr)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	init_assets(sol);
	assign_assets(sol, sol->mlx_ptr, SPRITE_SIZE);
	assign_assets_ennemies(sol, sol->mlx_ptr, SPRITE_SIZE);
	init_text(sol, 0, 0);
}
