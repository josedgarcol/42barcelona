/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:15:59 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/10 13:14:31 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current && current != node)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	sort(t_ctx *ctx)
{
	if (!ctx || is_sorted(&ctx->a))
		return ;
	if (ctx->flags.simple)
		sort_simple(ctx);
	else if (ctx->flags.medium)
		sort_medium(ctx);
	else if (ctx->flags.complex)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
}

void	sort_adaptive(t_ctx *ctx)
{
	if (ctx->a.size == 2)
		return (sort_two(ctx));
	if (ctx->a.size == 3)
		return (sort_three(ctx));
	if (ctx->a.size <= 5)
		return (sort_five(ctx));
	if (ctx->metrics.disorder < 0.2)
		sort_simple(ctx);
	else if (ctx->metrics.disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}

void	resolve_adaptive(t_ctx *ctx)
{
	if (ctx->metrics.disorder < 0.2)
		ctx->metrics.strategy = "Adaptive / O(n²)";
	else if (ctx->metrics.disorder < 0.5)
		ctx->metrics.strategy = "Adaptive / O(n√n)";
	else
		ctx->metrics.strategy = "Adaptive / O(n log n)";
}
