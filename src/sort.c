/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:10:23 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 18:05:54 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_elem **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	if (stack_size(*stack) == 2)
		return (ra(stack, 1));
	c = (*stack)->next->next->num;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	sort_five(t_elem **stack_a, t_elem **stack_b)
{
	int	smallest;
	int	second_smallest;

	smallest = find_smallest(*stack_a);
	second_smallest = find_second_smallest(*stack_a);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->num == smallest || (*stack_a)->num == second_smallest)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	move_back_to_a(t_elem **stack_a, t_elem **stack_b)
{
	t_elem	*max_node;
	int		position;

	while (*stack_b)
	{
		max_node = find_max(*stack_b);
		position = get_position(*stack_b, max_node);
		if (position <= stack_size(*stack_b) / 2)
		{
			while (*stack_b != max_node)
				rb(stack_b, 1);
		}
		else
		{
			while (*stack_b != max_node)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	opt_sort(t_elem **stack_a, t_elem **stack_b, int size, int chunks)
{
	int	threshold;
	int	mid_threshold;
	int	pushed;

	threshold = size / chunks;
	mid_threshold = (size / chunks) / 2;
	while (*stack_a)
	{
		pushed = 0;
		while (pushed < size / chunks && *stack_a)
		{
			if ((*stack_a)->index < threshold)
			{
				pb(stack_a, stack_b);
				pushed++;
				if (*stack_b && (*stack_b)->index < mid_threshold)
					rb(stack_b, 1);
			}
			else
				ra(stack_a, 1);
		}
		threshold += size / chunks;
		mid_threshold += size / chunks;
	}
}

void	sort(t_elem **stack_a, t_elem **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size <= 100)
	{
		sort_100(stack_a, stack_b, size);
	}
	else
	{
		opt_sort(stack_a, stack_b, size, 9);
		move_back_to_a(stack_a, stack_b);
	}
}
