/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_items_fieldstruct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:57:55 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/12 21:07:37 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	ft_check_presence_of_elem_in_map(char **map, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->count_collect++;
			if (map[i][j] == 'E')
				game->count_exits++;
			if (map[i][j] == 'P')
				game->count_players++;
			j++;
		}
		i++;
	}
	if (game->count_exits * game->count_players * game->count_collect == 0
		|| game->count_players != 1)
		ft_error_presence_elem_in_map();
}

void	set_pos_player(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	player_move(int x, int y, t_data *game)
{
	if (game->map[game->player_y + y][game->player_x + x] != '1')
	{
		if (game->map[game->player_y + y][game->player_x + x] == 'a' ||
				game->map[game->player_y + y][game->player_x + x] == 'b' ||
				game->map[game->player_y + y][game->player_x + x] == 'c' ||
				game->map[game->player_y + y][game->player_x + x] == 'd' ||
				game->map[game->player_y + y][game->player_x + x] == 'e' ||
				game->map[game->player_y + y][game->player_x + x] == 'f')
			game->count_collect--;
		if (game->map[game->player_y + y][game->player_x + x] != 'E')
		{
			game->map[game->player_y + y][game->player_x + x] = 'P';
			game->map[game->player_y][game->player_x] = '0';
			game->player_y += y;
			game->player_x += x;
			game->count_steps++;
			ft_putnbr_fd(game->count_steps, 1);
			ft_putstr_fd("\n", 1);
		}
		else if (game->count_collect == 0)
			exit(0);
	}
}

void	show_collects(t_data *game, char symb, int x, int y)
{
	if (symb == 'a')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[0].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'b')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[1].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'c')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[2].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'd')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[3].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'e')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[4].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'f')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect[5].addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	set_collect_symbols(char **map)
{
	int		i;
	int		j;
	char	sym;

	i = 0;
	sym = 'a';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				map[i][j] = sym++;
			if (sym == 'g')
				sym = 'a';
			j++;
		}
		i++;
	}
}
