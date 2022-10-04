/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:11:48 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/04 14:05:55 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*elt;
	void	*tmp;

	if (!lst)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		elt = ft_lstnew(tmp);
		if (!elt)
		{
			ft_lstclear(&ptr, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&ptr, elt);
		lst = lst->next;
	}
	return (ptr);
}
