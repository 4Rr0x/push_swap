/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:40:32 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/31 17:25:53 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*find_max(t_elem *stack)
{
	t_elem	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->num > max_node->num)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	ext_error(t_elem *stack_a, t_elem *stack_b, char **split)
{
	if (split)
		free_split(split);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putendl_fd("Error", 2);
	exit(1);
}
