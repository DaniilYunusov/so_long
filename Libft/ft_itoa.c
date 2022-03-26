/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:37:33 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/17 21:40:54 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_min_int_or_zero(int n)
{
	char	*res;

	if (n == 0)
	{
		res = ft_strdup("0");
		if (res == NULL)
			return (NULL);
	}
	else
	{
		res = ft_strdup("-2147483648");
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

static int	ft_num_of_char(int n)
{
	int	i;
	int	n_copy;

	i = 0;
	n_copy = n;
	if (n < 0)
		i++;
	while (n_copy != 0)
	{
		n_copy /= 10;
		i++;
	}
	return (i);
}

static char	*basic_logic(int n)
{
	int		i;
	char	*res;

	i = ft_num_of_char(n);
	if (n < 0)
		n *= -1;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	res[0] = '-';
	while (n != 0)
	{
		res[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648 || n == 0)
		return (ft_min_int_or_zero(n));
	return (basic_logic(n));
}
