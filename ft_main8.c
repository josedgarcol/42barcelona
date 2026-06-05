/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:54:30 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/05 20:24:59 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//int	ft_atoi(const char *nptr);
int	ft_nbrlen(long n);
char	*ft_itoa(int n);

int	main(void)
{
		long	n;

		n = ft_nbrlen(1234);
		printf("%ld", n);

		char	*s;
		long		x;

		x = -2147483647;

		s = ft_itoa(x);
		printf("\n%s", s);
}








/*
	char	stra[] = "holamundo";
	//char	stra[] = "";
	char	*p;

	p = ft_substr(stra, 4, 2);
	printf("%s\n", p);//(char *)ft_substr(stra, 4, 2));
	free((p);
	printf("%s\n", p);
}
*/
/*
int	main(void)
{
	char	str[] = " 	21474836471";
	char	str2[] = " 	21474836471";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str2));
}*/
