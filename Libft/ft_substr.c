/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:38:32 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/16 15:25:23 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (s == 0)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
