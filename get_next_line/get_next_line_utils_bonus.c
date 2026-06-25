/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:37:47 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/25 16:58:59 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	if (!s)
		return (0);
	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*p;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		s2 = "";
	if (!s1)
		s1 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	p = joined;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*new_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

void	delete_node(t_list **lst, int fd)
{
	t_list	*cur;
	t_list	*prev;

	if (!lst || !*lst)
		return ;
	cur = *lst;
	prev = NULL;
	while (cur && cur->fd != fd)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	if (!prev)
		*lst = cur->next;
	else
		prev->next = cur->next;
	free(cur->stash);
	free(cur);
}
