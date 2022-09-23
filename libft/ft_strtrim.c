/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:25:17 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/22 18:43:37 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (((char *)s1)[i] && (ft_char_in_string((char *)set, ((char *)s1)[i])
		|| ft_is_space(s1[i])))
		i++;
	return (i);
}

static	int	ft_trim_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (((char *)s1)[i] && (ft_char_in_string((char *)set, ((char *)s1)[i])
		|| ft_is_space(s1[i])))
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_trim_start(s1, set);
	if (len != (int)ft_strlen(s1))
		len += ft_trim_end(s1, set);
	else
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * ((int)ft_strlen(s1) - len + 1));
	if (!ptr)
		return (NULL);
	i = ft_trim_start(s1, set);
	j = 0;
	while (i < (int)ft_strlen(s1) - ft_trim_end(s1, set))
	{
		ptr[j] = ((char *)s1)[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
