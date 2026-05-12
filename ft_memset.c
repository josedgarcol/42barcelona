/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:28:21 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/11 15:51:45 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *ptr, int c, size_t len)
{
    unsigned char    *a;

    a = ptr;
    while (len--)
    {
        *a++ = (unsigned char) c;
    }
    return (ptr);
}
