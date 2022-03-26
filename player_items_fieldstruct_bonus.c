/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_items_fieldstruct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:58:40 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 17:01:24 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

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
			if (map[i][j] == 'X')
				game->count_enemy++;
			j++;
		}
		i++;
	}
	allocate_enemy(game);
	if (game->count_exits * game->count_players * game->count_collect == 0
		|| game->count_players != 1)
		ft_error_presence_elem_in_map();
}

void	set_pos_player_help(int i, int j, t_data *game)
{
	if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		game->map[i][j] = '0';
	}
}

void	set_pos_player(t_data *game)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			set_pos_player_help(i, j, game);
			if (game->map[i][j] == 'X')
			{
				game->enemy_x[x] = j;
				game->enemy_y[x] = i;
				game->map[i][j] = '0';
				x++;
			}
			j++;
		}
		i++;
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
