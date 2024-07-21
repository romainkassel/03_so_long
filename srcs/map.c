/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:26:43 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 09:56:04 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	store_map(t_sol *sol, char *argv1)
{
	int	fd;
	int	i;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		quit_game(sol, E_BAD_OPEN, FAILURE);
	get_map_height(sol, argv1);
	sol->map = (char **)malloc(sizeof(char *) * (sol->map_height + 1));
	if (!sol->map)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	i = 0;
	while (i < sol->map_height)
		sol->map[i++] = get_next_line(fd);
	sol->map[i] = 0;
	close(fd);
}

char	**get_mapcpy(char **map, t_sol *sol)
{
	int		i;
	char	**mapcpy;

	mapcpy = (char **)malloc(sizeof(char *) * (sol->map_height + 1));
	if (!mapcpy)
		quit_game(sol, E_BAD_MALLOC, FAILURE);
	i = 0;
	while (i < sol->map_height)
	{
		mapcpy[i] = ft_strdup(map[i]);
		i++;
	}
	mapcpy[i] = 0;
	return (mapcpy);
}

void	flood_fill(t_sol *sol, int x, int y, char **mapcpy)
{
	if (x < 1 || y < 1
		|| x >= sol->map_width || y >= sol->map_height
		|| mapcpy[y][x] == '1' || mapcpy[y][x] == 'F')
		return ;
	if (mapcpy[y][x] == 'E')
	{
		sol->e_collected++;
		mapcpy[y][x] = '1';
		return ;
	}
	if (mapcpy[y][x] == 'P')
		sol->p_collected++;
	else if (mapcpy[y][x] == 'C')
		sol->c_collected++;
	else
		sol->o_collected++;
	mapcpy[y][x] = 'F';
	flood_fill(sol, x - 1, y, mapcpy);
	flood_fill(sol, x + 1, y, mapcpy);
	flood_fill(sol, x, y - 1, mapcpy);
	flood_fill(sol, x, y + 1, mapcpy);
}

int	is_valid_path(t_sol *sol)
{
	char	**mapcpy;

	sol->p_collected = 0;
	sol->c_collected = 0;
	sol->e_collected = 0;
	mapcpy = get_mapcpy(sol->map, sol);
	flood_fill(sol, sol->start_pos_x, sol->start_pos_y, mapcpy);
	free_map(mapcpy);
	if (sol->p_collected != 1
		|| sol->c_collected != sol->c_init_nb
		|| sol->e_collected != 1)
		quit_game(sol, E_NO_VALID_PATH, FAILURE);
	return (SUCCESS);
}

int	check_map_format(char *arg)
{
	int	len;

	len = ft_strlen(arg) - 1;
	if (arg[len] == 'r' && arg[len - 1] == 'e'
		&& arg[len - 2] == 'b' && arg[len - 3] == '.')
		return (SUCCESS);
	else
		return (FAILURE);
}
