/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:25 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/13 15:18:10 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	void	*null_ptr;
	char	*null_str;
	int		x;

	null_ptr = NULL;
	null_str = NULL;
	x = 42;

	printf("pf:  [%c]\n", 'A');
	ft_printf("ft:  [%c]\n", 'A');
	printf("pf:  [%c]\n", '\0');
	ft_printf("ft:  [%c]\n", '\0');

	printf("pf:  [%s]\n", "hola mundo");
	ft_printf("ft:  [%s]\n", "hola mundo");
	printf("pf:  [%s]\n", "");
	ft_printf("ft:  [%s]\n", "");

	printf("pf:  [%s]\n", null_str);
	ft_printf("ft:  [%s]\n", null_str);

	printf("pf:  [%d]\n", 0);
	ft_printf("ft:  [%d]\n", 0);
	printf("pf:  [%d]\n", 42);
	ft_printf("ft:  [%d]\n", 42);
	printf("pf:  [%d]\n", -42);
	ft_printf("ft:  [%d]\n", -42);
	printf("pf:  [%d]\n", INT_MAX);
	ft_printf("ft:  [%d]\n", INT_MAX);
	printf("pf:  [%d]\n", INT_MIN);
	ft_printf("ft:  [%d]\n", INT_MIN);
	printf("pf:  [%i]\n", -1);
	ft_printf("ft:  [%i]\n", -1);

	printf("pf:  [%u]\n", 0U);
	ft_printf("ft:  [%u]\n", 0U);
	printf("pf:  [%u]\n", UINT_MAX);
	ft_printf("ft:  [%u]\n", UINT_MAX);
	printf("pf:  [%u]\n", 2147483648U);
	ft_printf("ft:  [%u]\n", 2147483648U);
	printf("pf:  [%u]\n", (unsigned int)-1);
	ft_printf("ft:  [%u]\n", (unsigned int)-1);

	printf("pf:  [%x]\n", 0);
	ft_printf("ft:  [%x]\n", 0);
	printf("pf:  [%x]\n", 255);
	ft_printf("ft:  [%x]\n", 255);
	printf("pf:  [%x]\n", UINT_MAX);
	ft_printf("ft:  [%x]\n", UINT_MAX);
	printf("pf:  [%X]\n", 0xABC);
	ft_printf("ft:  [%X]\n", 0xABC);
	printf("pf:  [%X]\n", UINT_MAX);
	ft_printf("ft:  [%X]\n", UINT_MAX);

	printf("pf:  [%p]\n", (void *)&x);
	ft_printf("ft:  [%p]\n", (void *)&x);

	printf("pf:  [%p]\n", null_ptr);
	ft_printf("ft:  [%p]\n", null_ptr);

	printf("pf:  [%%]\n");
	ft_printf("ft:  [%%]\n");

	printf("pf:  %s=%d hex=%x ptr=%p\n", "val", -99, 255, (void *)&x);
	ft_printf("ft:  %s=%d hex=%x ptr=%p\n", "val", -99, 255, (void *)&x);
	printf("pf:  [%c][%s][%d][%u][%x][%X][%%]\n", 'Z', "ok", -1, 99U, 16, 255);
	ft_printf("ft:  [%c][%s][%d][%u][%x][%X][%%]\n", 'Z', "ok", -1, 99U, 16, 255);

	fd = dup(1);
	close(1);
	ft_printf("esto no se imprime");
	dup2(fd, 1);
	close(fd);
	if (fd == -1)
		printf("ft_printf con stdout cerrado: \033[32m-1 ✓\033[0m\n");
	else
		printf("ft_printf con stdout cerrado: \033[31m-1 ✗\033[0m\n");

	ft_printf("%.0s", NULL);
	//printf("%.0s", NULL);
	return (0);
}
/*
{
    unsigned int max = 4294967295U;
    unsigned int min = 0U;
    unsigned int medio = 2147483648U;  // 2^31, justo el límite de int con signo

    ft_printf("Máximo: %u\n", max);
    printf("Máximo: %u\n", max);

    ft_printf("Mínimo: %u\n", min);
    printf("Mínimo: %u\n", min);

    ft_printf("Medio: %u\n", medio);
    printf("Medio: %u\n", medio);

    // También prueba con un número negativo convertido a unsigned
    int negativo = -1;
    ft_printf("-1 como unsigned: %u\n", (unsigned int)negativo);
    printf("-1 como unsigned: %u\n", (unsigned int)negativo);

    unsigned int	num = 123;
    unsigned int	num2 = 0xABC;
    int	x = 42;
    void *ptr = &x;

    ft_printf("%x\n", num);
    printf("%x\n", num);

    ft_printf("%X\n", num2);
    printf("%X\n", num2);

    ft_printf("%p\n", ptr);
    printf("%p\n", ptr);

    ft_printf("Hola %s, %d, %x, %p, %%\n", "mundo", 42, 255, ptr);
    printf("Hola %s, %d, %x, %p, %%\n", "mundo", 42, 255, ptr);
    printf("\n");
    ft_printf("%%");
    printf("%%");


    return (0);
}*/
