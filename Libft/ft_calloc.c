/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:24:36 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/13 18:54:03 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*res;
	size_t	quan;

	quan = count * size;
	res = (size_t *)malloc(quan * sizeof(char));
	if (res != NULL)
		ft_bzero(res, quan);
	return (res);
}
