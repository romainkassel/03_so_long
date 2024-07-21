/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:11:23 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 10:15:06 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_map_height(t_sol *sol, char *argv1)
{
	int		fd;
	char	*tmp;

	sol->map_height = 0;
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		quit_game(sol, E_BAD_OPEN, FAILURE);
	tmp = get_next_line(fd);
	if (tmp)
		sol->map_height++;
	while (tmp)
		(free(tmp), tmp = get_next_line(fd), sol->map_height++);
	sol->map_height--;
	free(tmp);
	close(fd);
}

void	get_map_data(t_sol *sol)
{
	int	i;
	int	j;

	i = 0;
	while (sol->map[i])
	{
		j = 0;
		while (sol->map[i][j] != '\n' && sol->map[i][j])
		{
			if (sol->map[i][j] == 'P')
			{
				sol->start_pos_x = j;
				sol->start_pos_y = i;
			}
			j++;
			sol->map_width = j;
		}
		i++;
	}
}

void	get_win_size(t_sol *sol)
{
	sol->win_w = sol->map_width * SPRITE_SIZE;
	sol->win_h = sol->map_height * SPRITE_SIZE;
}

void	get_data(t_sol *sol)
{
	get_map_data(sol);
	get_win_size(sol);
}
