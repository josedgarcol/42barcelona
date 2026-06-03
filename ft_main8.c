/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:54:30 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/03 18:56:23 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

//int	ft_atoi(const char *nptr);

int	main(void)
{
	printf("ft_strchr(\"#\", '#') = %p\n", ft_strchr("#", '#'));
	printf("ft_strchr(\"#\", 'a') = %p\n", ft_strchr("#", 'a'));
	char	*s;

	s = ft_strtrim("##hola##", "#");
	printf("%s", s);
	free(s);
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
