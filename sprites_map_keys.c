/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_map_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:18:30 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/12 21:23:26 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	entering_files(t_data *game, t_img *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (img->addr == NULL)
	{
		write(1, "Failed to upload sprite!\n", 25);
		exit(0);
	}
}

void	get_sprites(t_data *game)
{
	entering_files(game, &game->empty, "./sprites/Background/Empty.xpm");
	entering_files(game, &game->wall, "./sprites/Background/Brick_Wall.xpm");
	entering_files(game, &game->player_right, "./sprites/player1.xpm");
	entering_files(game, &game->player_left, "./sprites/player1r.xpm");
	entering_files(game, &game->collect[0], "./sprites/Items/coin.xpm");
	entering_files(game, &game->collect[1], "./sprites/Items/backpack.xpm");
	entering_files(game, &game->collect[2], "./sprites/Items/document.xpm");
	entering_files(game, &game->collect[3], "./sprites/Items/gemRed.xpm");
	entering_files(game, &game->collect[4], "./sprites/Items/scroll.xpm");
	entering_files(game, &game->collect[5], "./sprites/Items/envelope.xpm");
	entering_files(game, &game->exit_close, "./sprites/exit_close.xpm");
	entering_files(game, &game->exit_open, "./sprites/exit_open.xpm");
}

int	show_sprite(t_data *game, char symb, int x, int y)
{
	if (symb == 'a' || symb == 'b' || symb == 'c'
		|| symb == 'd' || symb == 'e' || symb == 'f')
		show_collects(game, symb, x, y);
	if (symb == 'P' && game->curs == 'r')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_right.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (symb == 'P' && game->curs == 'l')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_left.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
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

int	show_map(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->empty.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
			show_sprite(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	key_press_react(int key, t_data *game)
{
	if (key == 53)
		close_window();
	if (key == 0)
	{
		player_move(-1, 0, game);
		game->curs = 'l';
	}
	if (key == 2)
	{
		player_move(1, 0, game);
		game->curs = 'r';
	}
	if (key == 1)
		player_move(0, 1, game);
	if (key == 13)
		player_move(0, -1, game);
	return (0);
}
