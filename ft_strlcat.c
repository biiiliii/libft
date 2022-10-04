/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:07:29 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/15 12:37:54 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				j;
	unsigned int	k;
	unsigned int	i;

	i = 0;
	j = 0;
	k = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (dest[k])
		k++;
	if (size <= k)
		return (size + j);
	i = 0;
	while (size && (--size - k) && src[i])
	{
		dest[k + i] = src[i];
		i++;
	}
	dest[k + i] = '\0';
	return (j + k);
}
