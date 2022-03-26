/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:08:45 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/13 19:14:30 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_s;
	size_t	i;

	i = 0;
	copy_s = (char *) ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (copy_s != NULL)
	{
		while (s1[i])
		{
			copy_s[i] = s1[i];
			i++;
		}
	}
	return (copy_s);
}
