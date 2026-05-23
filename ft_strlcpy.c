/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:56:17 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/23 19:58:52 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (siz == 0)
		return (len);
	i = 0;
	while (src[i] && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
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
