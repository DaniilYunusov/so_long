/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_show_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:52:13 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/18 03:00:43 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	get_sprites_not_incoming(t_data *game)
{
	entering_files(game, &game->enemy_left[4], "./sprites/death5_l.xpm");
	entering_files(game, &game->enemy_left[5], "./sprites/death6_l.xpm");
	entering_files(game, &game->enemy_left[6], "./sprites/death7_l.xpm");
	entering_files(game, &game->enemy_left[7], "./sprites/death8_l.xpm");
	entering_files(game, &game->enemy_right[0], "./sprites/death1_r.xpm");
	entering_files(game, &game->enemy_right[1], "./sprites/death2_r.xpm");
	entering_files(game, &game->enemy_right[2], "./sprites/death3_r.xpm");
	entering_files(game, &game->enemy_right[3], "./sprites/death4_r.xpm");
	entering_files(game, &game->enemy_right[4], "./sprites/death5_r.xpm");
	entering_files(game, &game->enemy_right[5], "./sprites/death6_r.xpm");
	entering_files(game, &game->enemy_right[6], "./sprites/death7_r.xpm");
	entering_files(game, &game->enemy_right[7], "./sprites/death8_r.xpm");
	entering_files(game, &game->collect[0], "./sprites/Items/coin.xpm");
	entering_files(game, &game->collect[1], "./sprites/Items/backpack.xpm");
	entering_files(game, &game->collect[2], "./sprites/Items/document.xpm");
	entering_files(game, &game->collect[3], "./sprites/Items/gemRed.xpm");
	entering_files(game, &game->collect[4], "./sprites/Items/scroll.xpm");
	entering_files(game, &game->collect[5], "./sprites/Items/envelope.xpm");
	entering_files(game, &game->exit_close, "./sprites/exit_close.xpm");
	entering_files(game, &game->exit_open, "./sprites/exit_open.xpm");
}

void	get_sprites(t_data *game)
{
	entering_files(game, &game->empty, "./sprites/Background/Empty.xpm");
	entering_files(game, &game->wall, "./sprites/Background/Brick_Wall.xpm");
	entering_files(game, &game->player_right[0], "./sprites/player_r_1.xpm");
	entering_files(game, &game->player_right[1], "./sprites/player_r_2.xpm");
	entering_files(game, &game->player_right[2], "./sprites/player_r_3.xpm");
	entering_files(game, &game->player_right[3], "./sprites/player_r_4.xpm");
	entering_files(game, &game->player_right[4], "./sprites/player_r_5.xpm");
	entering_files(game, &game->player_right[5], "./sprites/player_r_6.xpm");
	entering_files(game, &game->player_right[6], "./sprites/player_r_7.xpm");
	entering_files(game, &game->player_right[7], "./sprites/player_r_8.xpm");
	entering_files(game, &game->player_left[0], "./sprites/player_l_1.xpm");
	entering_files(game, &game->player_left[1], "./sprites/player_l_2.xpm");
	entering_files(game, &game->player_left[2], "./sprites/player_l_3.xpm");
	entering_files(game, &game->player_left[3], "./sprites/player_l_4.xpm");
	entering_files(game, &game->player_left[4], "./sprites/player_l_5.xpm");
	entering_files(game, &game->player_left[5], "./sprites/player_l_6.xpm");
	entering_files(game, &game->player_left[6], "./sprites/player_l_7.xpm");
	entering_files(game, &game->player_left[7], "./sprites/player_l_8.xpm");
	entering_files(game, &game->enemy_left[0], "./sprites/death1_l.xpm");
	entering_files(game, &game->enemy_left[1], "./sprites/death2_l.xpm");
	entering_files(game, &game->enemy_left[2], "./sprites/death3_l.xpm");
	entering_files(game, &game->enemy_left[3], "./sprites/death4_l.xpm");
	get_sprites_not_incoming(game);
}

int	show_sprite(t_data *game, char symb, int x, int y)
{
	if (symb == 'a' || symb == 'b' || symb == 'c'
		|| symb == 'd' || symb == 'e' || symb == 'f')
		show_collects(game, symb, x, y);
	if (symb == 'E' && game->count_collect != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_close.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (symb == 'E' && game->count_collect == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_open.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	return (1);
}

void	show_steps_level_counter(t_data *game)
{
	char	*steps;

	steps = ft_itoa(game->count_steps);
	mlx_string_put(game->mlx, game->win, game->columns * 64 / 2 - 52, 32,
		0xFFFFFFFF, "Steps: ");
	mlx_string_put(game->mlx, game->win, game->columns * 64 / 2 + 25, 32,
		0xFFFFFFFF, steps);
	steps = ft_itoa(ft_atoi(game->file_name));
	mlx_string_put(game->mlx, game->win, game->columns * 64 / 2 - 52, 10,
		0xFFFFFFFF, "LEVEL ");
	mlx_string_put(game->mlx, game->win, game->columns * 64 / 2 + 25, 10,
		0xFFFFFFFF, steps);
	free(steps);
}
