/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:12:48 by bimartin          #+#    #+#             */
/*   Updated: 2022/10/04 13:12:11 by bimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*=-=-=-=-=-=-=-=-=-=-[#include "libft.h"]-=-=-=-=-=-=-=-=-=-=-=*/
#ifndef LIBFT_H
# define LIBFT_H

/*=-=-=-=-=-=-=-=-=-=-[#include <*>]-=-=-=-=-=-=-=-=-=-=-=*/
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

/*=-=-=-=-=-=-=-=-=-=-[structs]-=-=-=-=-=-=-=-=-=-=-=*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*=-=-=-=-=-=-=-=-=-=-[ft_is*]-=-=-=-=-=-=-=-=-=-=-=*/
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

/*=-=-=-=-=-=-=-=-=-=-[string transformation]-=-=-=-=-=-=-=-=-=-=-=*/
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dest, char *src, unsigned int size);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, char *src, unsigned int size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*=-=-=-=-=-=-=-=-=-=-[ft_mem*]-=-=-=-=-=-=-=-=-=-=-=*/
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);

/*=-=-=-=-=-=-=-=-=-=-[memory]-=-=-=-=-=-=-=-=-=-=-=*/
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

/*=-=-=-=-=-=-=-=-=-=-[custom]-=-=-=-=-=-=-=-=-=-=-=*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);

/*=-=-=-=-=-=-=-=-=-=-[fd]-=-=-=-=-=-=-=-=-=-=-=*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*=-=-=-=-=-=-=-=-=-=-[function parameter]-=-=-=-=-=-=-=-=-=-=-=*/
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*=-=-=-=-=-=-=-=-=-=-[bonus]-=-=-=-=-=-=-=-=-=-=-=*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*=-=-=-=-=-=-=-=-=-=-[utils]-=-=-=-=-=-=-=-=-=-=-=*/
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_is_space(int c);
char		*ft_strrev(char *str);
int			ft_char_in_string(char *s, char c);

#endif
