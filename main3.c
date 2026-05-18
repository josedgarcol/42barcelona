/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:29:03 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/16 14:55:38 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main(void)
{
	char	src[] = "abcdef";
	char	dest[7];
	char	*s;

	s = memcpy(dest, 4 + src, 2);
	printf("%s\n", s);
	memcpy(dest, 4 + src, 2);
	printf("%s\n", dest);
	
	printf("%s\n", (char *)memcpy(dest, 4 + src, 2));
	
}
