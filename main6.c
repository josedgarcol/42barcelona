/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:00:21 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/25 14:26:37 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
size_t  strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);

int	main(void)
{
	char	stra[] = "abcdef";
	char	strb[20] = "";
	char	strc[] = "abcdef";
	char	strd[20] = "";
	size_t	limit;
	size_t	result1;
	size_t	result2;

	limit = 2;
	result1 =  ft_strlcpy(strb, stra, limit);
	printf("%zu\n%s\n", result1, strb);
	result2 = strlcpy(strd, strc, limit);
	printf("%zu\n%s\n", result2, strd);
	return (0);
}

//-lbsd funciones nativas de GNU
