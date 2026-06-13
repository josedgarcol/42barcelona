/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:32:35 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/13 16:35:54 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret_ft;
	int	ret_orig;

	ret_ft = ft_printf("%p\n", NULL);
	ret_orig = printf("%p\n", NULL);

	printf("r_ft: %d | r_orig: %d\n", ret_ft, ret_orig);
	return (0);
}
