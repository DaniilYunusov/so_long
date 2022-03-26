/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:23:54 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 17:27:16 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	ft_check_for_squareness(char **mass_of_strings)
{
	int	i;
	int	j;
	int	line_length;
	int	len;

	i = 0;
	while (mass_of_strings[i])
	{
		j = 0;
		line_length = 0;
		while (mass_of_strings[i][j])
		{
			if (mass_of_strings[i][j] != '\n')
				line_length++;
			j++;
		}
		if (i == 0)
			len = line_length;
		if (line_length != len)
		{
			write(1, "Map is not rectangular!\n", 24);
			exit (0);
		}
		i++;
	}
}

void	ft_check_for_valid_map(int strings_count)
{
	if (strings_count < 3)
	{
		write(1, "Invalid map!\n", 13);
		exit(0);
	}
}

void	ft_check_for_closed_map(char **map, char **argv, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	game->rows = ft_num_of_lines_in_file(argv);
	game->columns = (int)ft_strlen(map[0]) - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 && (map[i][j] != '1' && map[i][j] != '\n'))
				|| (i == game->rows - 1 && (map[i][j] != '1'
				&& map[i][j] != '\n'))
				|| (j == 0 && map[i][j] != '1') || (j == game->columns - 1
				&& map[i][j] != '1'))
			{
				write(1, "The map is not surrounded by walls!\n", 36);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_error_presence_elem_in_map(void)
{
	write(1, "No subject/exit/starting position!\n", 35);
	exit(0);
}

void	ft_check_incorrect_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != '\n' &&
				map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'X')
			{
				write(1, "Incorrect symbol in map!\n", 25);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
