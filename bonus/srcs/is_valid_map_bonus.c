/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:08:12 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 11:30:18 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	is_map_closed_by_walls(t_sol *sol, int map_height)
{
	int	i;
	int	j;

	map_height--;
	i = 0;
	while (sol->map[i])
	{
		j = 0;
		if (sol->map[i][j] != '1')
			quit_game(sol, E_MAP_NOT_CLOSED, FAILURE);
		while (sol->map[i][j] != '\n' && sol->map[i][j])
		{
			if ((i == 0 && sol->map[i][j] != '1')
				|| (i == map_height && sol->map[i][j] != '1'))
				quit_game(sol, E_MAP_NOT_CLOSED, FAILURE);
			j++;
		}
		if (sol->map[i][j - 1] != '1')
			quit_game(sol, E_MAP_NOT_CLOSED, FAILURE);
		i++;
	}
}

void	is_map_rect(t_sol *sol)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	line_len = 0;
	while (sol->map[i])
	{
		j = 0;
		while (sol->map[i][j] != '\n' && sol->map[i][j])
			j++;
		if (i == 0)
			line_len = j;
		if (j != line_len)
			quit_game(sol, E_MAP_NOT_RECT, FAILURE);
		i++;
	}
	if (i == line_len)
		quit_game(sol, E_MAP_NOT_RECT, FAILURE);
}

void	is_chars_accurate(t_sol *sol)
{
	int	i;
	int	j;

	i = 0;
	while (sol->map[i])
	{
		j = 0;
		while (sol->map[i][j] != '\n' && sol->map[i][j])
		{
			if (sol->map[i][j] != '0'
				&& sol->map[i][j] != '1'
				&& sol->map[i][j] != 'C'
				&& sol->map[i][j] != 'E'
				&& sol->map[i][j] != 'P'
				&& sol->map[i][j] != 'X')
				quit_game(sol, E_FORB_CHARS, FAILURE);
			j++;
		}
		i++;
	}
}

void	is_ecp_nb_accurate(t_sol *sol)
{
	int	i;
	int	j;

	i = 0;
	sol->p_init_nb = 0;
	sol->e_init_nb = 0;
	sol->c_init_nb = 0;
	while (sol->map[i])
	{
		j = 0;
		while (sol->map[i][j] != '\n' && sol->map[i][j])
		{
			if (sol->map[i][j] == 'E')
				sol->e_init_nb++;
			if (sol->map[i][j] == 'P')
				sol->p_init_nb++;
			if (sol->map[i][j] == 'C')
				sol->c_init_nb++;
			j++;
			sol->map_width = j;
		}
		i++;
	}
	if (sol->e_init_nb != 1 || sol->p_init_nb != 1 || sol->c_init_nb < 1)
		quit_game(sol, E_BAD_PEC_COUNT, FAILURE);
}

void	is_valid_map(t_sol *sol, int map_height)
{
	is_map_closed_by_walls(sol, map_height);
	is_map_rect(sol);
	is_chars_accurate(sol);
	is_ecp_nb_accurate(sol);
	is_valid_path(sol);
}
