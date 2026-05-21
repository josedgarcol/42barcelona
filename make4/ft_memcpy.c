/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:05:10 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/21 15:10:58 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char 	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	while(n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
