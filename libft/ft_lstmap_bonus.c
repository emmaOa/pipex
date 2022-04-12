/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:52:55 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/26 01:53:01 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	while (lst)
	{
		tmp = ft_lstnew(lst->content);
		if (!tmp)
			ft_lstclear(&lst, del);
		tmp->content = f(tmp->content);
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
