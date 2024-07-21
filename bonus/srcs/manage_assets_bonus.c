/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_assets_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:51:10 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:34:52 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	assign_assets_ennemies(t_sol *sol, void *mlx_ptr, int s)
{
	sol->text_x1 = mlx_xpm_file_to_image(mlx_ptr, "assets/X1.xpm", &s, &s);
	if (!sol->text_x1)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_x2 = mlx_xpm_file_to_image(mlx_ptr, "assets/X2.xpm", &s, &s);
	if (!sol->text_x2)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_x3 = mlx_xpm_file_to_image(mlx_ptr, "assets/X3.xpm", &s, &s);
	if (!sol->text_x3)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_x4 = mlx_xpm_file_to_image(mlx_ptr, "assets/X4.xpm", &s, &s);
	if (!sol->text_x4)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_x5 = mlx_xpm_file_to_image(mlx_ptr, "assets/X5.xpm", &s, &s);
	if (!sol->text_x5)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	sol->text_x6 = mlx_xpm_file_to_image(mlx_ptr, "assets/X6.xpm", &s, &s);
	if (!sol->text_x6)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
}

void	clean_images(t_sol *sol)
{
	if (sol->mlx_ptr && sol->text_1)
		mlx_destroy_image(sol->mlx_ptr, sol->text_1);
	if (sol->mlx_ptr && sol->text_0)
		mlx_destroy_image(sol->mlx_ptr, sol->text_0);
	if (sol->mlx_ptr && sol->text_c)
		mlx_destroy_image(sol->mlx_ptr, sol->text_c);
	if (sol->mlx_ptr && sol->text_e)
		mlx_destroy_image(sol->mlx_ptr, sol->text_e);
	if (sol->mlx_ptr && sol->text_pf)
		mlx_destroy_image(sol->mlx_ptr, sol->text_pf);
	if (sol->mlx_ptr && sol->text_pb)
		mlx_destroy_image(sol->mlx_ptr, sol->text_pb);
	if (sol->mlx_ptr && sol->text_pl)
		mlx_destroy_image(sol->mlx_ptr, sol->text_pl);
	if (sol->mlx_ptr && sol->text_pr)
		mlx_destroy_image(sol->mlx_ptr, sol->text_pr);
}

void	clean_images_ennemies(t_sol *sol)
{
	if (sol->mlx_ptr && sol->text_x1)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x1);
	if (sol->mlx_ptr && sol->text_x2)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x2);
	if (sol->mlx_ptr && sol->text_x3)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x3);
	if (sol->mlx_ptr && sol->text_x4)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x4);
	if (sol->mlx_ptr && sol->text_x5)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x5);
	if (sol->mlx_ptr && sol->text_x6)
		mlx_destroy_image(sol->mlx_ptr, sol->text_x6);
}
