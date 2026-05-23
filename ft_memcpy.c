/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:22:08 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/23 17:31:20 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	if (!d && !s)
		return (NULL);
	if (dest == src)
		return (dest);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "abcdef";
	char	dest[4];
	printf("%s\n", (char *)memcpy(dest, 1 + src, 1));

	printf("%s\n", (char *)ft_memcpy(dest, 1 + src, 1));
	return (0);
}*/


/*int	main(void)
{
	char	s[] = "sol";
	void	*result;

	result = ft_memcpy(NULL, s, 4);
	printf("Texto copiado: %s\n", (char *)result);

	return (0);

}*/
