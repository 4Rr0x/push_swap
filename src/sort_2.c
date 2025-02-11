/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:32:29 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 18:07:02 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_elem *stack, t_elem *target)
{
	int		pos;
	t_elem	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current == target)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

int	find_insert_position(t_elem *stack_a, int value)
{
	t_elem	*current;
	int		best_pos;
	int		best_value;

	best_pos = 0;
	best_value = __INT_MAX__;
	current = stack_a;
	while (current)
	{
		if (current->num > value && current->num < best_value)
		{
			best_value = current->num;
			best_pos = stack_size(current);
		}
		current = current->next;
	}
	return (best_pos);
}

int	find_smallest(t_elem *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void	sort_100(t_elem **stack_a, t_elem **stack_b, int size)
{
	int	position;

	while (*stack_b)
	{
		position = find_insert_position(*stack_a, (*stack_b)->num);
		while (position > 0)
		{
			ra(stack_a, 1);
			position--;
		}
		pa(stack_a, stack_b);
	}
	opt_sort(stack_a, stack_b, size, 6);
	move_back_to_a(stack_a, stack_b);
}
