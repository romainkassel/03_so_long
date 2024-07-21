/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:07 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/26 15:03:18 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	display_message(char *status_message, int exit_status)
{
	if (exit_status == FAILURE)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(status_message, 2);
		ft_putchar_fd('\n', 2);
	}
	else
	{
		ft_putstr_fd("Success\n", 1);
		ft_putstr_fd(status_message, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	clean(t_sol *sol)
{
	if (sol->map)
		free_map(sol->map);
	if (sol->mlx_ptr && sol->win_ptr)
		mlx_destroy_window(sol->mlx_ptr, sol->win_ptr);
	clean_images(sol);
	clean_images_ennemies(sol);
	if (sol->mlx_ptr)
	{
		mlx_destroy_display(sol->mlx_ptr);
		free(sol->mlx_ptr);
	}
}

int	clos_win(t_sol *sol)
{
	display_message(S_ESCAPE, SUCCESS);
	clean(sol);
	exit(SUCCESS);
}

void	quit_game(t_sol *sol, char *status_message, int exit_status)
{
	display_message(status_message, exit_status);
	clean(sol);
	exit(exit_status);
}
