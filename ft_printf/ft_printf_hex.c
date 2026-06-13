/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:08:31 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/13 14:20:54 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int n, int uppercase)
{
	char	*digits;
	char	buf[9];
	int		i;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	i = 8;
	buf[8] = '\0';
	while (n)
	{
		buf[--i] = digits[n % 16];
		n /= 16;
	}
	if (write(1, buf + i, 8 - i) == -1)
		return (-1);
	return (8 - i);
}

static int	ft_putptr_hex(unsigned long n)
{
	char	*digits;
	char	buf[17];
	int		i;

	digits = "0123456789abcdef";
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	i = 16;
	buf[16] = '\0';
	while (n)
	{
		buf[--i] = digits[n % 16];
		n /= 16;
	}
	if (write(1, buf + i, 16 - i) == -1)
		return (-1);
	return (16 - i);
}

int	print_hex(va_list args, int uppercase)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_put_hex(n, uppercase));
}

int	print_ptr(va_list args)
{
	void	*ptr;
	int		ret;
	int		len;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ret = write(1, "(nil)", 5);
		if (ret == -1)
			return (-1);
		return (5);
	}
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	len = ft_putptr_hex((unsigned long)ptr);
	if (len == -1)
		return (-1);
	return (2 + len);
}
