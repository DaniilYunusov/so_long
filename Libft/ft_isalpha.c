/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:24:04 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/10 20:52:59 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int s)
{
	if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
		return (1);
	else
		return (0);
}
