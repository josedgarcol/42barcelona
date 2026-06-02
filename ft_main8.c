/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:54:30 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/02 17:17:01 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

//int	ft_atoi(const char *nptr);

int	main(void)
{
	char	stra[] = "holamundo";
	//char	stra[] = "";
	char	*p;

	p = ft_substr(stra, 4, 2);
	printf("%s\n", p);//(char *)ft_substr(stra, 4, 2));
	free((p);
	printf("%s\n", p);
}

/*
int	main(void)
{
	char	str[] = " 	21474836471";
	char	str2[] = " 	21474836471";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str2));
}*/
