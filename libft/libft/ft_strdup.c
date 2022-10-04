/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:47:31 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/21 17:03:52 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (0);
	while (((char *)s1)[i])
	{
		cpy[i] = ((char *)s1)[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
