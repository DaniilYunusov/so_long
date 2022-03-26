/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:43:06 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/13 14:11:44 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	finish;

	sign = 1;
	finish = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		finish = (finish * 10 + (*str - '0'));
		str++;
	}
	if ((finish >= 9223372036854775807) && sign == 1)
		return (-1);
	if ((finish >= 9223372036854775807) && sign == -1)
		return (0);
	return ((int)finish * sign);
}