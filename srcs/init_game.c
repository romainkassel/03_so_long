/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:51:10 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/24 14:30:36 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

void	assign_assets(t_sol *sol, void *mlx_ptr, int s)
{
	sol->text_1 = mlx_xpm_file_to_image(mlx_ptr, "assets/1.xpm", &s, &s);
	if (!sol->text_1)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_0 = mlx_xpm_file_to_image(mlx_ptr, "assets/0.xpm", &s, &s);
	if (!sol->text_0)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_c = mlx_xpm_file_to_image(mlx_ptr, "assets/C.xpm", &s, &s);
	if (!sol->text_c)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_e = mlx_xpm_file_to_image(mlx_ptr, "assets/E.xpm", &s, &s);
	if (!sol->text_e)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_pf = mlx_xpm_file_to_image(mlx_ptr, "assets/Pf.xpm", &s, &s);
	if (!sol->text_pf)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_pb = mlx_xpm_file_to_image(mlx_ptr, "assets/Pb.xpm", &s, &s);
	if (!sol->text_pb)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_pl = mlx_xpm_file_to_image(mlx_ptr, "assets/Pl.xpm", &s, &s);
	if (!sol->text_pl)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_pr = mlx_xpm_file_to_image(mlx_ptr, "assets/Pr.xpm", &s, &s);
	if (!sol->text_pr)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
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
			display_text(sol, sol->map[i][j], x, y);
			j++;
		}
		i++;
	}
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
	init_text(sol, 0, 0);
}
