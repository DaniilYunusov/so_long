/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:19:02 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/12 21:44:57 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		j = 0;
		while (haystack[j] == needle[j] && haystack[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
