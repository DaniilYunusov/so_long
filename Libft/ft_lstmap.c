/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:04:35 by hjosua            #+#    #+#             */
/*   Updated: 2021/10/23 22:33:29 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*copy_list;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		copy_list = ft_lstnew(f(lst->content));
		if (!copy_list)
			ft_lstclear(&res, del);
		ft_lstadd_back(&res, copy_list);
		lst = lst->next;
	}
	return (res);
}
