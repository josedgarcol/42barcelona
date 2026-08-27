/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:28:01 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/04 19:32:50 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_byte;
	unsigned char	uc;

	s_byte = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*s_byte == uc)
			return (s_byte);
		s_byte++;
	}
	return (NULL);
}
