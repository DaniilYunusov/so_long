/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:40:18 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/12 19:51:25 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	dstsize -= ft_strlen(dst);
	while (*dst)
		dst++;
	dstsize--;
	while (dstsize-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_size + src_size);
}
