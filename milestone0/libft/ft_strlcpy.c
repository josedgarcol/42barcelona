/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:56:17 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/25 14:00:52 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	if (siz > 0)
	{
		i = 0;
		while (src[i] && i < (siz - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	const char 	*s;
	unsigned char	*d;

	s = src;
	d = (unsigned char *)dst;
	while (*s)
	{
		*d++ = (unsigned char)*s++;
		siz++;
	}
	siz[d] = '\0';
	return (siz);
}*/
