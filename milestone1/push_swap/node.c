/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:51:05 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 12:47:43 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->bottom)
	{
		stack->top = node;
		stack->bottom = node;
		stack->size = 1;
		return ;
	}
	node->prev = stack->bottom;
	stack->bottom->next = node;
	stack->bottom = node;
	stack->size++;
}

int	error_exit(t_ctx *ctx)
{
	free_stack(&ctx->a);
	free_stack(&ctx->b);
	write(2, "Error\n", 6);
	return (1);
}

void	init_ctx(t_ctx *ctx)
{
	ctx->a.top = NULL;
	ctx->a.bottom = NULL;
	ctx->a.size = 0;
	ctx->b.top = NULL;
	ctx->b.bottom = NULL;
	ctx->b.size = 0;
	ctx->metrics.disorder = 0.0;
	ctx->metrics.strategy = NULL;
	ctx->metrics.total = 0;
	ctx->metrics.sa = 0;
	ctx->metrics.sb = 0;
	ctx->metrics.ss = 0;
	ctx->metrics.pa = 0;
	ctx->metrics.pb = 0;
	ctx->metrics.ra = 0;
	ctx->metrics.rb = 0;
	ctx->metrics.rr = 0;
	ctx->metrics.rra = 0;
	ctx->metrics.rrb = 0;
	ctx->metrics.rrr = 0;
}
