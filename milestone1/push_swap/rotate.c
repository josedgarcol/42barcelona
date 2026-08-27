/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:49:14 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/28 20:47:30 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size < 2)
		return ;
	node = stack->top;
	stack->top = node->next;
	stack->top->prev = NULL;
	node->next = NULL;
	node->prev = stack->bottom;
	stack->bottom->next = node;
	stack->bottom = node;
}

void	ra(t_ctx *ctx)
{
	rotate_stack(&ctx->a);
	write (1, "ra\n", 3);
	ctx->metrics.ra++;
	ctx->metrics.total++;
}

void	rb(t_ctx *ctx)
{
	rotate_stack(&ctx->b);
	write (1, "rb\n", 3);
	ctx->metrics.rb++;
	ctx->metrics.total++;
}

void	rr(t_ctx *ctx)
{
	rotate_stack(&ctx->a);
	rotate_stack(&ctx->b);
	write (1, "rr\n", 3);
	ctx->metrics.rr++;
	ctx->metrics.total++;
}
