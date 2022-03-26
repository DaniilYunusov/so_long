/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:51:21 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 16:52:00 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

int	ft_check_extension(char *map_file)
{
	char	*extension;
	int		index;
	int		point_index;

	extension = ".ber";
	index = 0;
	while (map_file[index])
	{
		if (map_file[index] == '.')
			point_index = index;
		index++;
	}
	if (--index - point_index != 3)
		return (FALSE);
	index = 0;
	while (extension[index])
	{
		if (map_file[point_index] != extension[index])
			return (FALSE);
		index++;
		point_index++;
	}
	return (TRUE);
}

void	ft_errors_processing(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Incorrect number of arguments!\n", 31);
		exit (0);
	}
	if (!ft_check_extension(argv[1]))
	{
		write(1, "The argument must be an extension file .ber!\n", 45);
		exit (0);
	}
}

void	ft_invalid_fd(int fd)
{
	if (fd == -1)
	{
		write(1, "Problem with reading from a file!\n", 34);
		exit (0);
	}
}
