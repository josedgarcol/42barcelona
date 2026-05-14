/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:47:54 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/14 14:19:32 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "string.h"

int	main(void)
{
	printf("ft_isalpha %d\n", ft_isalpha('6'));
	printf("ft_isdigit %d\n", ft_isdigit('2'));
	printf("ft_isalnum %d\n", ft_isalnum('2'));
	printf("ft_isascii %d\n", ft_isascii(128));
	printf("ft_isprint %d\n", ft_isprint(126));
	printf("ft_strlen  %zu\n", ft_strlen("hola"));

	char	array[100];

	printf("ft_memset  %s\n", (char *)ft_memset(array, 'A', 5));
	printf("   memset  %s\n", (char *)memset(array, 'A', 5));

	char	*res;

	res = ft_memset(array, 'A', 5);
	printf("ft_memset  %s\n", res);
	printf("   memset  %s\n", res);

	char arrayb[100];
	char arrayb_a[100];

	printf("\n");
	ft_memset(arrayb, '?', 100);
	ft_memset(arrayb, 'A', 5);
	memset(arrayb_a, '#', 100);
	memset(arrayb_a, 'B', 5);
	printf("ft_memset %.20s\n", arrayb);
	printf("   memset %.20s\n", arrayb_a);

	char	arrayc[20];

	ft_memset(arrayc, '?', 20);
	arrayc[19] = '\0';

	ft_memset(&arrayc[7], 'C', 5);

	printf("ft_memset %s\n", arrayc);

	char	arrayc_a[20];

	memset(arrayc_a, '#', 20);
	arrayc_a[19] = '\0';

	memset(&arrayc_a[7], 'C', 5);

	printf("   memset %s\n", arrayc_a);

	//char	*str;
	//str = "abc";
	//str = ft_bzero(arrayc, 3);
	//printf("ft_bzero     %s\n", str);
	
	char	str[] = "hola mundo";
	ft_bzero(str, 1);
	printf("ft_bzero  %s\n", str);

	char	str_a[10];
	size_t	i;
	int	total;

	total = 0;
	i = 0;
	ft_bzero(str_a, sizeof(str_a));
	while (i < sizeof(str_a))
	{
	printf("%d | ", str_a[i]);
	total += printf("%d", str_a[i]);
	i++;
	}
	printf("\n%zu", sizeof(str_a));
	printf("\n%d", total);	
	printf("\n");
	return (0);
}











