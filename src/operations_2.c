/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:32:52 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/31 17:28:28 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_elem **stack)
{
	t_elem	*first;
	t_elem	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
}

void	sb(t_elem **stack)
{
	t_elem	*first;
	t_elem	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sb\n");
}

void	rra(t_elem **stack)
{
	t_elem	*last;
	t_elem	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}

void	rrb(t_elem **stack)
{
	t_elem	*last;
	t_elem	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
}

int	find_second_smallest(t_elem *stack)
{
	int	smallest;
	int	second;

	second = __INT_MAX__;
	smallest = find_smallest(stack);
	while (stack)
	{
		if (stack->num > smallest && stack->num < second)
			second = stack->num;
		stack = stack->next;
	}
	return (second);
}
