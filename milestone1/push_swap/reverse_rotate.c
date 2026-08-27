/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:50:50 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/28 19:58:31 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = node->prev;
	stack->bottom->next = NULL;
	node->prev = NULL;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
}

void	rra(t_ctx *ctx)
{
	reverse_rotate_stack(&ctx->a);
	write (1, "rra\n", 4);
	ctx->metrics.rra++;
	ctx->metrics.total++;
}

void	rrb(t_ctx *ctx)
{
	reverse_rotate_stack(&ctx->b);
	write (1, "rrb\n", 4);
	ctx->metrics.rrb++;
	ctx->metrics.total++;
}

void	rrr(t_ctx *ctx)
{
	reverse_rotate_stack(&ctx->a);
	reverse_rotate_stack(&ctx->b);
	write (1, "rrr\n", 4);
	ctx->metrics.rrr++;
	ctx->metrics.total++;
}
