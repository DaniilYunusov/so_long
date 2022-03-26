/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:03:14 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/10 22:19:31 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*copy_s;
	char		copy_c;
	size_t		i;

	copy_c = (char)c;
	copy_s = NULL;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == copy_c)
			copy_s = s + i;
		i++;
	}
	if (*(s + i) == copy_c)
		copy_s = s + i;
	return ((char *)copy_s);
}
