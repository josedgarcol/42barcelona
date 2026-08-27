/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:32:35 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/16 15:41:36 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret;

    ret = ft_printf("%z");
    printf("%d\n", ret);
    return (0);
}


/*{
	int	ret_ft;
	//int	ret_orig;
	ret_ft = ft_printf("");
	printf("%d\n", ret_ft);
	//ret_ft = ft_printf(NULL);
	//ret_orig = printf(NULL);
	//printf("r_ft: %d\n", ret_ft);
	return (0);
}*/
