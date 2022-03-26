/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:07:30 by hjosua            #+#    #+#             */
/*   Updated: 2021/11/19 21:34:11 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(char *rem)
{
	char	*string;
	int		str_l;
	char	*p_sln;
	int		i;

	str_l = 0;
	i = 0;
	if (!rem[str_l])
		return (NULL);
	p_sln = ft_strchr(rem, '\n');
	if (!p_sln)
		return (ft_strjoin("", rem));
	while (&rem[str_l] != p_sln)
		str_l++;
	string = (char *) malloc((str_l + 2) * sizeof(char ));
	if (!string)
		return (NULL);
	while (str_l >= i)
	{
		string[i] = rem[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_buf_use(char *rem, int fd)
{
	char	*buf;
	char	*help_str;
	ssize_t	subt;

	subt = 1;
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char ));
	if (!buf)
		return (NULL);
	while (!ft_strchr(rem, '\n') && subt > 0)
	{
		subt = read(fd, buf, BUFFER_SIZE);
		if (subt <= 0)
			break ;
		buf[subt] = '\0';
		help_str = ft_strjoin(rem, buf);
		if (!help_str)
			return (NULL);
		free(rem);
		rem = help_str;
	}
	free(buf);
	return (rem);
}

char	*ft_modific_rem(char *rem)
{
	char	*p_sln;
	char	*res_rem;
	size_t	i;
	size_t	copy_i;

	p_sln = ft_strchr(rem, '\n');
	if (!p_sln)
	{
		free(rem);
		return (NULL);
	}
	p_sln++;
	i = ft_strlen(p_sln);
	copy_i = 0;
	res_rem = (char *) malloc((i + 1) * sizeof(char ));
	if (!res_rem)
		return (NULL);
	while (copy_i <= i)
	{
		res_rem[copy_i] = p_sln[copy_i];
		copy_i++;
	}
	free(rem);
	return (res_rem);
}

char	*get_next_line(int fd)
{
	static char		*rem;
	char			*string;

	if (read(fd, (void *)0, 0))
		return (NULL);
	rem = ft_buf_use(rem, fd);
	if (!rem)
		return (NULL);
	string = ft_find_line(rem);
	rem = ft_modific_rem(rem);
	return (string);
}
