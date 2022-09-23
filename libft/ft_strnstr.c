/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:52 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/21 16:37:36 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	tmp;
	char	*hs;

	hs = (char *)haystack;
	if (ft_strlen(needle) == 0 || needle == NULL)
		return (hs);
	i = 0;
	tmp = 0;
	while (hs[i] && i < len)
	{
		if (hs[i] == ((char *)needle)[tmp])
			tmp++;
		else
		{
			if (tmp != 0)
				i -= tmp;
			tmp = 0;
		}
		if (tmp == ft_strlen(needle))
			return (&hs[i - tmp + 1]);
		i++;
	}
	return (NULL);
}
