/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:59:14 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/13 13:34:15 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_count(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	handle_conversion(char spec, va_list args)
{
	if (spec == 'c')
		return (print_char(args));
	if (spec == 's')
		return (print_str(args));
	if (spec == 'd' || spec == 'i')
		return (print_int(args));
	if (spec == 'u')
		return (print_uint(args));
	if (spec == 'x')
		return (print_hex(args, 0));
	if (spec == 'X')
		return (print_hex(args, 1));
	if (spec == 'p')
		return (print_ptr(args));
	if (spec == '%')
		return (print_percent());
	return (0);
}

static int	ft_handle_char(const char *s, int *i, va_list args)
{
	int	ret;

	if (s[*i] == '%' && s[*i + 1])
	{
		(*i)++;
		ret = handle_conversion(s[*i], args);
		(*i)++;
	}
	else
	{
		ret = ft_putchar_count(s[*i]);
		(*i)++;
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		ret;

	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		ret = ft_handle_char(s, &i, args);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
	}
	va_end(args);
	return (count);
}
