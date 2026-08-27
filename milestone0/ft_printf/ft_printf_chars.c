/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:34:47 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/14 16:44:51 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	char	c;
	int		ret;

	c = (char)va_arg(args, int);
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (1);
}

int	print_str(va_list args)
{
	char	*s;
	int		len;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

int	print_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
