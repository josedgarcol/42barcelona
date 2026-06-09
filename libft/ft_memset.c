/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:28:21 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/20 20:48:07 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)ptr;
	while (len--)
	{
		*a++ = (unsigned char) c;
	}
	return (ptr);
}
/*
int	main(void)
{
	int	s[] = {1, 2, 3};

	ft_memset(s, 'a', 1);

	printf("s[0]: %d (Hex: 0x%X), s[1]: %d, s[2]: %d\n", s[0], s[0], s[1], s[2]);
	return (0);
}*/
