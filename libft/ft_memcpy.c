/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:22:08 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/14 18:45:41 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s;

	s = dest;
	while (n--)
	{
		*s++ = (:xsrc
	}


	return(dest);
}

int	main(void)
{
	char	dest[] = "ABCD";
	char	src[] = "---";
	printf("%s\n", (char *)memcpy(dest, src, 1));
	return (0);
}
