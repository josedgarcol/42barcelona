/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:00:21 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/23 19:55:52 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
size_t  strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);

int	main(void)
{
	char	stra[] = "abcdef";
	char	strb[] = "";
	char	strc[] = "abcdef";
	char	strd[] = "";
	size_t	limit;
	size_t	result;

	limit = 2;
	printf("%zu\n%s\n", ft_strlcpy(strb, stra, limit), strb);
	result = strlcpy(strd, strc, limit);
	printf("%zu\n%s\n", result, strd);
	return (0);
}
