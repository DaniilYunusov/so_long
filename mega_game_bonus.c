/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:56:20 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/26 20:31:46 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	t_map_ber_completion(t_map_ber *mapBer)
{
	mapBer->args[0] = "./so_long_bonus";
	mapBer->args[1] = NULL;
	mapBer->args[2] = NULL;
	mapBer->pid = 0;
	mapBer->map_ber[0] = "1_level.ber";
	mapBer->map_ber[1] = "2_level.ber";
	mapBer->map_ber[2] = "3_level.ber";
	mapBer->map_ber[3] = "4_level.ber";
	mapBer->map_ber[4] = NULL;
	mapBer->i = 0;
	mapBer->status = 0;
}

int	main(void)
{
	t_map_ber	levels;

	t_map_ber_completion(&levels);
	while (levels.map_ber[levels.i])
	{
		levels.pid = fork();
		if (levels.pid == 0)
		{
			levels.args[1] = levels.map_ber[levels.i];
			execve(levels.args[0], levels.args, NULL);
		}
		else
		{
			waitpid(levels.pid, &levels.status, 0);
			if (levels.status == 0)
				exit(0);
			if (levels.status == 256)
			{
				++levels.i;
				printf("GO TO LVL %d\n", levels.i + 1);
			}
			if (levels.status == 512)
				printf("Restart lvl %d\n", levels.i + 1);
		}
	}
}
