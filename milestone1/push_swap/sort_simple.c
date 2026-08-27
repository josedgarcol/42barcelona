/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:47:21 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 11:17:40 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_ctx *ctx)
{
	if (!ctx || ctx->a.size < 2)
		return ;
	if (ctx->a.top->index > ctx->a.top->next->index)
		sa(ctx);
}

void	sort_three(t_ctx *ctx)
{
	t_node	*highest;
	t_node	*current;

	if (!ctx || ctx->a.size != 3)
		return ;
	highest = ctx->a.top;
	current = ctx->a.top->next;
	while (current)
	{
		if (current->index > highest->index)
			highest = current;
		current = current->next;
	}
	if (ctx->a.top == highest)
		ra(ctx);
	else if (ctx->a.top->next == highest)
		rra(ctx);
	if (ctx->a.top->index > ctx->a.top->next->index)
		sa(ctx);
}

void	sort_five(t_ctx *ctx)
{
	t_node	*target_node;
	int		target;
	int		position;

	target = 0;
	while (ctx->a.size > 3)
	{
		target_node = find_index(&ctx->a, target);
		position = get_position(&ctx->a, target_node);
		if (position <= ctx->a.size / 2)
		{
			while (ctx->a.top != target_node)
				ra(ctx);
		}
		else
		{
			while (ctx->a.top != target_node)
				rra(ctx);
		}
		pb(ctx);
		target++;
	}
	sort_three(ctx);
	while (ctx->b.size)
		pa(ctx);
}

void	sort_simple(t_ctx *ctx)
{
	t_node	*min;
	int		pos;
	int		target_index;

	target_index = 0;
	while (ctx->a.size > 0)
	{
		min = find_index(&ctx->a, target_index);
		if (!min)
			break ;
		pos = get_position(&ctx->a, min);
		if (pos <= ctx->a.size / 2)
			while (ctx->a.top != min)
				ra(ctx);
		else
			while (ctx->a.top != min)
				rra(ctx);
		pb(ctx);
		target_index++;
	}
	while (ctx->b.size)
		pa(ctx);
}
