/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:14:41 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/05 13:51:38 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	counter_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !(*(s + 1))))
			words++;
		s++;
	}
	return (words);
}

char	**fill_array(char const *s, char c, char **str_array)
{
	size_t	i;
	size_t	str_len;
	size_t	i_str;

	i_str = 0;
	i = 0;
	while (s[i])
	{
		str_len = 1;
		if (s[i] != c)
		{
			while (s[i + str_len] && s[i + str_len] != c)
				str_len++;
			str_array[i_str++] = ft_substr(s, i, str_len);
			if (!str_array[i_str - 1])
			{
				while (i_str--)
					free(str_array[i_str]);
				free(str_array);
				return (NULL);
			}
		}
		i += str_len;
	}
	return (str_array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	words;

	if (!s)
		return (NULL);
	words = counter_words(s, c);
	str_array = malloc(sizeof(char *) * (words + 1));
	if (!str_array)
		return (NULL);
	str_array[words] = NULL;
	if (words == 0)
		return (str_array);
	if (!fill_array(s, c, str_array))
		return (NULL);
	return (str_array);
}
/*  | *(s + 1) == '\0') |
*/
