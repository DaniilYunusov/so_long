/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:57:01 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/10 22:55:42 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*copy_src;

	copy_src = src;
	if (dstsize)
	{
		while (dstsize-- - 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (ft_strlen(copy_src));
}
