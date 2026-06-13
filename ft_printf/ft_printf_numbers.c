/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:06:47 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/13 11:49:45 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbrlen(unsigned int n)
{
	int	len;

	len = (n == 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unbrlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n)
		{
			str[--len] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

int	print_int(va_list args)
{
	int		n;
	char	*str;
	int		len;
	int		ret;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	ret = write(1, str, len);
	free (str);
	if (ret == -1)
		return (-1);
	return (len);
}

int	print_uint(va_list args)
{
	unsigned int	u;
	char			*str;
	int				len;
	int				ret;

	u = va_arg(args, unsigned int);
	str = ft_utoa(u);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	ret = write(1, str, len);
	free (str);
	if (ret == -1)
		return (-1);
	return (len);
}
