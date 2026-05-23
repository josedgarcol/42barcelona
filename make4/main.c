/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:08:13 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/21 21:18:53 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	array[7] = "______";
	char	array2[7] = "abcdef";
	char	array3[7] = "abcdef";

	//printf("%s", (char *)ft_memset(array , 'a', sizeof(char) * 2));
	//printf("%s", (char *)ft_memset(array , 'a', ft_strlen(array) + 1));
	//printf("%s", (char *)ft_memset(array , 'a', sizeof(array)));
	//printf("%s\n", (char *)ft_memset(array , 'a', sizeof(char) * 2));

	//printf("%s\n", array);

	//printf("%s\n", (char *)ft_memcpy(array, array2 + 5, sizeof(char) * 2));
	//printf("%s\n", (char *)ft_memcpy(array2 + 2, array2 + 1, sizeof(char) * 2));

	//printf("%s\n", (char *)ft_memmove(array2 + 2, array2 + 1, sizeof(char) * 2));
	//printf("%s\n", (char *)memmove(array3 + 2, array3 + 1, sizeof(char) * 2));
	printf("%s\n", (char *)ft_memmove(array2 + 1, array2 + 2, sizeof(char) * 2));
	printf("%s\n", (char *)memmove(array3 + 1, array3 + 2, sizeof(char) * 2));
	return (0);
}
