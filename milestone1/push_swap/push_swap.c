/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:36:44 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 11:51:28 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_flags(t_flags *flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
}

int	is_flag(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "--simple"))
		return (1);
	if (!ft_strcmp(str, "--medium"))
		return (1);
	if (!ft_strcmp(str, "--complex"))
		return (1);
	if (!ft_strcmp(str, "--adaptive"))
		return (1);
	if (!ft_strcmp(str, "--bench"))
		return (1);
	return (0);
}

int	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	i = 1;
	while (i < argc && argv[i])
	{
		if (!ft_strcmp(argv[i], "--simple"))
			flags->simple += 1;
		else if (!ft_strcmp(argv[i], "--medium"))
			flags->medium += 1;
		else if (!ft_strcmp(argv[i], "--complex"))
			flags->complex += 1;
		else if (!ft_strcmp(argv[i], "--adaptive"))
			flags->adaptive += 1;
		else if (!ft_strcmp(argv[i], "--bench"))
			flags->bench += 1;
		i++;
	}
	return (i);
}

int	validate_flags(t_flags *flags, t_metrics *metrics)
{
	int	strategies;

	strategies = flags->simple
		+ flags->medium
		+ flags->complex
		+ flags->adaptive;
	if (strategies > 1 || flags->bench > 1)
		return (0);
	if (strategies == 0)
		flags->adaptive = 1;
	if (flags->simple)
		metrics->strategy = "Simple / O(n²)";
	else if (flags->medium)
		metrics->strategy = "Medium / O(n√n)";
	else if (flags->complex)
		metrics->strategy = "Complex / O(n log n)";
	else
		metrics->strategy = "Adaptive";
	return (1);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		return (0);
	init_ctx(&ctx);
	init_flags(&ctx.flags);
	parse_flags(argc, argv, &ctx.flags);
	if (!validate_flags(&ctx.flags, &ctx.metrics))
		return (error_exit(&ctx));
	if (parse_arguments(argc, argv, &ctx))
		return (1);
	assign_indexes(&ctx.a);
	ctx.metrics.disorder = compute_disorder(&ctx.a);
	if (ctx.flags.adaptive)
		resolve_adaptive(&ctx);
	sort(&ctx);
	if (ctx.flags.bench)
		print_metrics(&ctx);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
