/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:41:35 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 15:12:04 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

typedef struct s_metrics
{
	double	disorder;
	char	*strategy;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_metrics;

typedef struct s_ctx
{
	t_stack		a;
	t_stack		b;
	t_flags		flags;
	t_metrics	metrics;
}	t_ctx;

/* push_swap.c */
void	init_flags(t_flags *flags);
int		is_flag(char *str);
int		parse_flags(int argc, char **argv, t_flags *flags);
int		validate_flags(t_flags *flags, t_metrics *metrics);

/* parser.c */
int		parse_arguments(int argc, char **argv, t_ctx *ctx);

/* node.c */
t_node	*new_node(int value);
void	stack_add_bottom(t_stack *stack, t_node *node);
int		error_exit(t_ctx *ctx);
void	init_ctx(t_ctx *ctx);
void	free_stack(t_stack *stack);

/* index.c */
void	assign_indexes(t_stack *stack);
t_node	*find_index(t_stack *stack, int index);
int		is_sorted(t_stack *stack);
double	compute_disorder(t_stack *stack);

/* sort.c */
void	sort(t_ctx *ctx);
void	sort_adaptive(t_ctx *ctx);
void	resolve_adaptive(t_ctx *ctx);
int		get_position(t_stack *stack, t_node *node);

/* sort_simple.c */
void	sort_simple(t_ctx *ctx);
void	sort_two(t_ctx *ctx);
void	sort_three(t_ctx *ctx);
void	sort_five(t_ctx *ctx);

/* sort_medium.c */
void	sort_medium(t_ctx *ctx);

/* sort_complex.c */
void	sort_complex(t_ctx *ctx);

/* metrics.c */
void	print_metrics(t_ctx *ctx);

/* ft_printf */
int		ft_printf(int fd, const char *format, ...);

/* gnl_utils.c */
int		ft_strcmp(const char *s1, const char *s2);

/* Operations */
/* swap.c */
void	sa(t_ctx *ctx);
void	sb(t_ctx *ctx);
void	ss(t_ctx *ctx);
/* push.c */
void	pa(t_ctx *ctx);
void	pb(t_ctx *ctx);
/* rotate.c */
void	ra(t_ctx *ctx);
void	rb(t_ctx *ctx);
void	rr(t_ctx *ctx);
/* reverse_rotate.c */
void	rra(t_ctx *ctx);
void	rrb(t_ctx *ctx);
void	rrr(t_ctx *ctx);

#endif
