/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:41:04 by jcolque           #+#    #+#             */
/*   Updated: 2026/05/23 16:08:20 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main(void)
{
	char	stra[] = "abcdef";
	char	strb[] = "abcdef";
	char	strc[] = "abcdef";

	printf("%s\n", (ft_memmove(stra, stra + 1, sizeof(char) * 5), stra));
	printf("%s\n", (ft_memmove(strb + 1, strb, sizeof(char) * 5), strb));
	printf("%s\n", (ft_memmove(strc, strc, sizeof(char) * 5), strc));
	//printf("%s", (memmove(strb, strb + 1, sizeof(char) * 5), strb));
}
