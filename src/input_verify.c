/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:52:37 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 17:43:49 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_indices(t_elem *stack)
{
	t_elem	*current;
	t_elem	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->num > compare->num)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_ordered(t_elem *stack)
{
	int	max;

	max = 0;
	while (stack->next)
	{
		if (stack->num > max)
			max = stack->num;
		else
			return (0);
	}
	return (1);
}

int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[j])
	{
		i = 0;
		if (ft_issign(av[j][i]) && av[j][i + 1] != '\0')
			i++;
		while (av[j][i] && ft_isdigit(av[j][i]))
			i++;
		if (av[j][i] != '\0' && !ft_isdigit(av[j][i]))
			return (0);
		j++;
	}
	return (1);
}

int	has_dupes(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **av)
{
	if (!check_digit(av) || !has_dupes(av))
		return (0);
	return (1);
}
