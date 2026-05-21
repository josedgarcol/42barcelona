/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:26:48 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/21 14:12:45 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*ptr_b;

	ptr_b = (unsigned char *)ptr;

	while(n--)
	{
		*ptr_b++ = (unsigned char)c;
	}
	return (ptr);
}
