/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:47:44 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/28 20:52:32 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src || !dst || src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else
		dst->bottom = node;
	dst->top = node;
	dst->size++;
}

void	pa(t_ctx *ctx)
{
	if (ctx->b.size == 0)
		return ;
	push_stack(&ctx->b, &ctx->a);
	write (1, "pa\n", 3);
	ctx->metrics.pa++;
	ctx->metrics.total++;
}

void	pb(t_ctx *ctx)
{
	if (ctx->a.size == 0)
		return ;
	push_stack(&ctx->a, &ctx->b);
	write (1, "pb\n", 3);
	ctx->metrics.pb++;
	ctx->metrics.total++;
}
