/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:55:40 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/04 13:07:03 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*todel;

	tmp = *lst;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		del(todel->content);
		free(todel);
	}
	*lst = NULL;
}
