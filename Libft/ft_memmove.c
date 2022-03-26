/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:45 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/10 21:06:53 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	if (copy_dst < copy_src)
		while (len--)
			*copy_dst++ = *copy_src++;
	else
	{
		copy_src += len - 1;
		copy_dst += len - 1;
		while (len--)
		{
			*copy_dst-- = *copy_src--;
		}
	}
	return (dst);
}
