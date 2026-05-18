/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:06:31 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/15 14:28:55 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (i < argc)
		{
			printf("Arg [%d]: %s\n", i, argv[i]);
			i++;
		}
	printf("argc: %d\n", argc);
	}
	return (0);
}
