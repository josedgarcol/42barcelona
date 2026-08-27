/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:34:04 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 15:11:46 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	if (!stack)
		return (0);
	max_index = stack->size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_ctx *ctx)
{
	int	max_bits;
	int	size;
	int	bit;
	int	i;

	if (!ctx || ctx->a.size <= 1)
		return ;
	size = ctx->a.size;
	max_bits = get_max_bits(&ctx->a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((ctx->a.top->index >> bit) & 1) == 0)
				pb(ctx);
			else
				ra(ctx);
			i++;
		}
		while (ctx->b.size)
			pa(ctx);
		bit++;
	}
}
