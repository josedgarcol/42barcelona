/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:13:16 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/20 20:48:29 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isalnum('b'));
	printf("%d\n", ft_isascii(128));
	printf("%d\n", ft_isprint(' '));
	printf("%zu\n", ft_strlen("abc\0\0"));

	char	s[] = "abcd";

	//printf("%s\n\n", (char *)ft_memset(s, '7', 1));
	//ft_bzero(s + 2, 1);
	//printf("%s\n", s);
	printf("\n%s\n", (char *)ft_memcpy(s, s + 2, 2));
	char	s2[] = "abcd";
	printf("\n%s\n", (char *)ft_memcpy(s2, s2 + 1, 2));
	char	s3[] = "abcd";
	printf("\n%s\n", (char *)ft_memcpy(s3 + 1, s3, 2));

	int	s4[] = };

	printf("%d", ft_memset(s4, 'a', 2));
	return (0);
}
