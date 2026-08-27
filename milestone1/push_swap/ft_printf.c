/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:28:49 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 12:18:29 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	ft_putstr_fd(const char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
		len++;
	write(fd, s, (size_t)len);
	return (len);
}

static int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return ((int)write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

static int	ft_putfloat_fd(double f, int fd)
{
	int	integer;
	int	decimal;
	int	count;

	count = 0;
	if (f < 0)
	{
		count += ft_putchar_fd('-', fd);
		f = -f;
	}
	integer = (int)f;
	decimal = (int)((f - integer) * 100);
	count += ft_putnbr_fd(integer, fd);
	count += ft_putchar_fd('.', fd);
	if (decimal < 10)
		count += ft_putchar_fd('0', fd);
	count += ft_putnbr_fd(decimal, fd);
	return (count);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				count += ft_putstr_fd(va_arg(args, char *), fd);
			else if (*format == 'd')
				count += ft_putnbr_fd(va_arg(args, int), fd);
			else if (*format == 'f')
				count += ft_putfloat_fd(va_arg(args, double), fd);
			else if (*format == '%')
				count += ft_putchar_fd('%', fd);
		}
		else
			count += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(args);
	return (count);
}
