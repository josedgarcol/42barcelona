/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:41:57 by jcolque           #+#    #+#             */
/*   Updated: 2026/07/28 20:51:04 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_metric_line1(t_metrics *m)
{
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		m->sa, m->sb, m->ss, m->pa, m->pb);
}

static void	write_metric_line2(t_metrics *m)
{
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		m->ra, m->rb, m->rr, m->rra, m->rrb, m->rrr);
}

void	print_metrics(t_ctx *ctx)
{
	t_metrics	*m;

	m = &ctx->metrics;
	ft_printf(2, "[bench] disorder:   %f%%\n", m->disorder * 100);
	ft_printf(2, "[bench] strategy:   %s\n", m->strategy);
	ft_printf(2, "[bench] total_ops:  %d\n", m->total);
	write_metric_line1(m);
	write_metric_line2(m);
}
