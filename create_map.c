/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:57:59 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/12 20:52:09 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	ft_num_of_lines_in_file(char **argv)
{
	int		fd;
	int		i;
	char	*string;

	fd = open(argv[1], O_RDONLY);
	ft_invalid_fd(fd);
	i = 0;
	string = get_next_line(fd);
	while (string)
	{
		if (ft_strlen(string) > 1)
			i++;
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	*ft_create_string_in_map_array(char *string)
{
	char	*string_map;
	int		i;

	i = 0;
	string_map = (char *) malloc(sizeof(char ) * (ft_strlen(string) + 1));
	while (string[i])
	{
		string_map[i] = string[i];
		i++;
	}
	string_map[i] = '\0';
	free(string);
	return (string_map);
}

int	ft_check_str_for_only_line_break(char *string)
{
	if (ft_strlen(string) == 1 && string[0] == '\n')
		return (FALSE);
	return (TRUE);
}

char	**ft_create_map_array(char **argv)
{
	int		fd;
	char	*string;
	int		strings_count;
	int		j;
	char	**mass_of_strings;

	strings_count = ft_num_of_lines_in_file(argv);
	ft_check_for_valid_map(strings_count);
	fd = open(argv[1], O_RDONLY);
	ft_invalid_fd(fd);
	mass_of_strings = (char **) malloc(sizeof(char *) * strings_count + 1);
	j = 0;
	string = get_next_line(fd);
	while (string)
	{
		if (ft_check_str_for_only_line_break(string))
		{
			mass_of_strings[j] = ft_create_string_in_map_array(string);
			j++;
		}
		string = get_next_line(fd);
	}
	mass_of_strings[j] = NULL;
	close(fd);
	return (mass_of_strings);
}

char	**ft_map_parsing(char **argv, t_data *game)
{
	char	**map_array;

	ft_zeroing_fields(game);
	map_array = ft_create_map_array(argv);
	ft_check_for_squareness(map_array);
	ft_check_for_closed_map(map_array, argv, game);
	ft_check_presence_of_elem_in_map(map_array, game);
	ft_check_incorrect_symbols(map_array);
	return (map_array);
}
