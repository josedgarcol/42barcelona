/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:59:14 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/09 18:16:42 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int	printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if
	}
}
