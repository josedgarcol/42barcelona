/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:06:18 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/18 17:38:55 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char 		*d;
	const unsigned char 	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	if (s > d)
	{
		while (n--)
			*d++ = *s++;
	}
	if (s < d)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
/*
int	main(void)
{
	char	s1[] = "abcdef";
	ft_memmove(s1, s1 + 2, 4);
	printf ("%s\n", s1);

	char	s2[] = "abcdef";
	ft_memmove(s2 + 2, s2, 4);
	printf("%s\n", s2);

	char	s3[] = "abcdef";
	ft_memmove(s3, s3, 6);
	printf("%s\n", s3);

	return (0);
}*/
