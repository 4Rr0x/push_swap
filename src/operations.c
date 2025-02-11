/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:57:39 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 11:40:26 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_elem **stack_a, int flag)
{
	t_elem	*temp;
	t_elem	*last;

	if (!stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_elem **stack_b, int flag)
{
	t_elem	*temp;
	t_elem	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_elem **stack_a, t_elem **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}

void	pb(t_elem **stack_a, t_elem **stack_b)
{
	t_elem	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_printf("pb\n");
}

void	pa(t_elem **stack_a, t_elem **stack_b)
{
	t_elem	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_printf("pa\n");
}
