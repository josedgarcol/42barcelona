/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:46:19 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/28 20:46:50 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}

void	sa(t_ctx *ctx)
{
	swap_stack(&ctx->a);
	write(1, "sa\n", 3);
	ctx->metrics.sa++;
	ctx->metrics.total++;
}

void	sb(t_ctx *ctx)
{
	swap_stack(&ctx->b);
	write(1, "sb\n", 3);
	ctx->metrics.sb++;
	ctx->metrics.total++;
}

void	ss(t_ctx *ctx)
{
	swap_stack(&ctx->a);
	swap_stack(&ctx->b);
	write (1, "ss\n", 3);
	ctx->metrics.ss++;
	ctx->metrics.total++;
}
