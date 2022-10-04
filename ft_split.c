/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:16 by bimartin          #+#    #+#             */
/*   Updated: 2022/09/28 14:27:19 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(char *s, char c)
{
	int	i;
	int	words;

	if (!c)
		return (0);
	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i])
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static	int	ft_word_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i++] != '\0')
		len++;
	return (len);
}

static	char	*ft_allocate_word(char *s, int i, int len)
{
	int		j;
	char	*word;

	if (!s)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

void	*ft_free(char **word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr;
	int		word_len;
	int		j;

	ptr = (char **)malloc(sizeof(char *) * (ft_count_words((char *)s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (((char *)s)[i])
	{
		if ((char)s[i] == c)
			i++;
		else
		{
			word_len = ft_word_len((char *)s, c, i);
			ptr[j] = ft_allocate_word((char *)s, i, word_len);
			if (!ptr[j++])
				return (ft_free(ptr));
			i += word_len;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}
