/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:28:59 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_sol	sol;

	sol.map = NULL;
	sol.win_ptr = NULL;
	sol.mlx_ptr = NULL;
	if (argc != 2 || check_map_format(argv[1]) == FAILURE)
		return (display_message(E_WRONG_ARG, FAILURE), FAILURE);
	store_map(&sol, argv[1]);
	get_data(&sol);
	is_valid_map(&sol, sol.map_height);
	init_game(&sol);
	sol.c_collected_play = 0;
	sol.mov_nb = 0;
	mlx_hook(sol.win_ptr, KeyPress, KeyPressMask, &move_player, &sol);
	mlx_hook(sol.win_ptr, DestroyNotify, StructureNotifyMask, &clos_win, &sol);
	mlx_loop(sol.mlx_ptr);
	return (SUCCESS);
}
