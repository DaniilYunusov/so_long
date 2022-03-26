/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:01:11 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/10 21:27:20 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	unsigned char	copy_c;
	size_t			i;

	copy_s = (unsigned char *)s;
	copy_c = (unsigned char)c;
	i = 0;
	while (i != n)
	{
		if (*(copy_s + i) == copy_c)
			return (copy_s + i);
		i++;
	}
	return (NULL);
}
