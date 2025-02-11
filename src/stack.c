/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:39:19 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/31 17:24:46 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*crt_stack(char **av)
{
	t_elem	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (av[i])
	{
		add_to_stack(&stack, ft_atoi(av[i]));
		i++;
	}
	assign_indices(stack);
	return (stack);
}

t_elem	*crt_elem(int value)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->num = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_elem **stack, int num)
{
	t_elem	*new_node;
	t_elem	*temp;

	new_node = crt_elem(num);
	if (!new_node)
		ext_error(*stack, NULL);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	free_stack(t_elem *stack)
{
	t_elem	*temp;

	while (stack)
	{
		temp = stack;
		stack = (stack)->next;
		free(temp);
	}
}

int	stack_size(t_elem *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
