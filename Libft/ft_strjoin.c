/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:48:01 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/16 16:18:10 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *) malloc(size_s1 + size_s2 + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i != size_s1 + size_s2)
	{
		if (i < size_s1)
			res[i] = s1[i];
		else
			res[i] = s2[i - size_s1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
