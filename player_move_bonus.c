/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:01:41 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 17:03:15 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	player_move_2(int x, int y, t_data *game)
{
	if (game->map[game->player_y + y][game->player_x + x] == 'a'
		|| game->map[game->player_y + y][game->player_x + x] == 'b'
		|| game->map[game->player_y + y][game->player_x + x] == 'c'
		|| game->map[game->player_y + y][game->player_x + x] == 'd'
		|| game->map[game->player_y + y][game->player_x + x] == 'e'
		|| game->map[game->player_y + y][game->player_x + x] == 'f')
		game->count_collect--;
}

void	player_move_1(int x, int y, t_data *game)
{
	if (game->map[game->player_y + y][game->player_x + x] != '1')
	{
		player_move_2(x, y, game);
		if (game->map[game->player_y + y][game->player_x + x] == 'E')
		{
			if (game->count_collect == 0)
				exit(1);
			game->player_y += y;
			game->player_x += x;
			game->count_steps++;
			ft_putnbr_fd(game->count_steps, 1);
			ft_putstr_fd("\n", 1);
		}
		else
		{
			if (game->map[game->player_y][game->player_x] != 'E')
				game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y + y][game->player_x + x] = '0';
			game->player_y += y;
			game->player_x += x;
			game->count_steps++;
			ft_putnbr_fd(game->count_steps, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	player_move(int x, int y, t_data *game)
{
	enemy_move(game, x, y);
	if (death_win(game, x, y))
		exit(2);
	player_move_1(x, y, game);
}
