/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:52:54 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/10 14:33:43 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int total)
{
	int	root;

	root = 1;
	while (root * root < total)
		root++;
	return ((root * 3) / 2);
}

static void	push_to_b(t_ctx *ctx, int chunk)
{
	int	i;

	i = 0;
	while (ctx->a.size)
	{
		if (ctx->a.top->index <= i)
		{
			pb(ctx);
			rb(ctx);
			i++;
		}
		else if (ctx->a.top->index <= i + chunk)
		{
			pb(ctx);
			i++;
		}
		else
			ra(ctx);
	}
}

static void	empty_b_to_a(t_ctx *ctx)
{
	t_node	*target;
	int		idx;
	int		pos;

	idx = ctx->b.size - 1;
	while (idx >= 0)
	{
		target = find_index(&ctx->b, idx);
		pos = get_position(&ctx->b, target);
		if (pos <= ctx->b.size / 2)
		{
			while (ctx->b.top != target)
				rb(ctx);
		}
		else
		{
			while (ctx->b.top != target)
				rrb(ctx);
		}
		pa(ctx);
		idx--;
	}
}

void	sort_medium(t_ctx *ctx)
{
	int	chunk;

	if (!ctx || ctx->a.size <= 1)
		return ;
	chunk = chunk_size(ctx->a.size);
	push_to_b(ctx, chunk);
	empty_b_to_a(ctx);
}
