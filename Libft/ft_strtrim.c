/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:28:56 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/16 18:55:41 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	p;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	p = 0;
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == j)
		return ((char *)ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[j]))
		j--;
	res = (char *) malloc((ft_strlen(s1) - i
				- (ft_strlen(s1) - j) + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i <= j)
		res[p++] = s1[i++];
	res[p] = '\0';
	return (res);
}
