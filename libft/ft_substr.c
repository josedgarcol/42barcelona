/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:22:39 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/02 17:07:47 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*new_s;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (*s == 0 || start > (unsigned int)(s_len - 1))
		return (ft_strdup(""));
	if (len <= (s_len - start))
		new_s = malloc(len + 1);
	else
		new_s = malloc((s_len - start) + 1);
	if (!new_s)
		return (NULL);
	while (s[i + start] && (i < len))
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
