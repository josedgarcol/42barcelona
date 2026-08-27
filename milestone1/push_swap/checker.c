/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:33:34 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 12:36:26 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec_move_swap_rotate(t_ctx *ctx, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_stack(&ctx->a);
	else if (!ft_strcmp(line, "sb\n"))
		swap_stack(&ctx->b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap_stack(&ctx->a);
		swap_stack(&ctx->b);
	}
	else if (!ft_strcmp(line, "ra\n"))
		rotate_stack(&ctx->a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_stack(&ctx->b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate_stack(&ctx->a);
		rotate_stack(&ctx->b);
	}
	else
		return (0);
	return (1);
}

static int	exec_move(t_ctx *ctx, char *line)
{
	if (exec_move_swap_rotate(ctx, line))
		return (1);
	if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_stack(&ctx->a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_stack(&ctx->b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate_stack(&ctx->a);
		reverse_rotate_stack(&ctx->b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push_stack(&ctx->b, &ctx->a);
	else if (!ft_strcmp(line, "pb\n"))
		push_stack(&ctx->a, &ctx->b);
	else
		return (0);
	return (1);
}

static int	is_sorted_ch(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	read_and_exec(t_ctx *ctx)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_move(ctx, line))
		{
			free(line);
			error_exit(ctx);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		return (0);
	init_ctx(&ctx);
	if (parse_arguments(argc, argv, &ctx))
		return (1);
	if (!ctx.a.top)
		return (free_stack(&ctx.a), 0);
	read_and_exec(&ctx);
	if (is_sorted_ch(&ctx.a) && !ctx.b.top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
