/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:16:44 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/29 20:24:28 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

size_t	strlcat(char *dst, const char *src, size_t siz);

int	main(void)
{
	char		dst[5] = "hola";
	const char	src[6] = "mundo";
	char		dst_b[5] = "hola";
	const char	src_b[6] = "mundo";
	size_t		siz;

	siz = 10;
	printf("%zu\n%s\n", strlcat(dst, src, siz), dst);
	printf("%zu\n%s\n", ft_strlcat(dst_b, src_b, siz), dst_b);
}


/*{
	char		strdst[7] = "abcdef";
	const char	strsrc[] = "linux";

	printf("%zu\n%s", strlcat(strdst, strsrc, 7), strdst);
}*/
