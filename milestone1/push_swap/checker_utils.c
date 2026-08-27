/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:30:45 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/10 15:22:38 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	parse_int(char **s, int *value)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -sign;
		(*s)++;
	}
	if (!(**s >= '0' && **s <= '9'))
		return (0);
	while (**s >= '0' && **s <= '9')
	{
		num = num * 10 + (**s - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && num > 2147483648L))
			return (0);
		(*s)++;
	}
	if (**s && **s != ' ' && **s != '\t')
		return (0);
	*value = (int)(num * sign);
	return (1);
}

static int	parse_argument_string(char *s, t_ctx *ctx)
{
	int		value;
	t_node	*node;

	if (!*s)
		return (error_exit(ctx));
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (!*s)
			break ;
		if (!parse_int(&s, &value))
			return (error_exit(ctx));
		if (is_duplicate(&ctx->a, value))
			return (error_exit(ctx));
		node = new_node(value);
		if (!node)
			return (error_exit(ctx));
		stack_add_bottom(&ctx->a, node);
	}
	return (0);
}

int	parse_arguments(int argc, char **argv, t_ctx *ctx)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (parse_argument_string(argv[i], ctx))
			return (1);
		i++;
	}
	return (0);
}
