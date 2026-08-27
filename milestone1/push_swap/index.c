/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcolque <jcolque@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:22:53 by jcolque           #+#    #+#             */
/*   Updated: 2026/08/03 11:27:53 by jcolque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	size_t	mistakes;
	size_t	total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((double)mistakes / (double)total_pairs);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	int		index;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		index = 0;
		runner = stack->top;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

t_node	*find_index(t_stack *stack, int index)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}
