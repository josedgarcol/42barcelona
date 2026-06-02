/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:36:59 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/02 19:53:02 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_a;
	size_t	len_b;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	len_a = ft_strlen(s1);
	len_b = ft_strlen(s2);
	joined = (char *)malloc(len_a + len_b + 1);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, len_a);
	ft_memcpy(joined + len_a, s2, len_b + 1);
	return (joined);
}
