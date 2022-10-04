/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:49:41 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/22 18:08:37 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_num_len(int n)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		n *= -1;
		c++;
	}
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static	char	*neg_and_end(char	*ptr, int neg, int i)
{
	if (neg)
		ptr[i++] = '-';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ptr = (char *)malloc((ft_num_len(n) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	while (n > 0)
	{
		ptr[i++] = (n % 10) + 48;
		n /= 10;
	}
	return (ft_strrev(neg_and_end(ptr, negative, i)));
}
