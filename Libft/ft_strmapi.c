/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:05:30 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/17 21:39:27 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*res;
	unsigned int	p;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	p = 0;
	res = (char *)malloc((i + 1) * sizeof(char ));
	if (res == NULL)
		return (NULL);
	while (s[p])
	{
		res[p] = (*f)(p, s[p]);
		p++;
	}
	res[p] = '\0';
	return (res);
}
