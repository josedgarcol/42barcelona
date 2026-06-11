/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:25 by jcolque           #+#    #+#             */
/*   Updated: 2026/06/11 19:31:23 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
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
}
