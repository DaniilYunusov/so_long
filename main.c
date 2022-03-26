/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:54:11 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/12 20:56:50 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	main(int argc, char **argv)
{
	t_data	game;
	t_data	win;

	ft_errors_processing(argc, argv);
	game.map = ft_map_parsing(argv, &game);
	set_pos_player(&game);
	set_collect_symbols(game.map);
	game.mlx = mlx_init();
	get_sprites(&game);
	game.win = mlx_new_window(game.mlx, game.columns * SPRITE_SIZE,
			game.rows * SPRITE_SIZE, "so_long");
	mlx_loop_hook(game.mlx, show_map, &game);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press_react, &game);
	mlx_loop(game.mlx);
}
