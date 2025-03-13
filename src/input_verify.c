/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:36:06 by jopedro-          #+#    #+#             */
/*   Updated: 2025/03/11 14:59:41 by jopedro-         ###   ########.fr       */
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
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_digit(char **av)
{
	int	tmp;
	int	sign;
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		tmp = 0;
		sign = 1;
		if (ft_issign(av[j][i]) && av[j][i + 1] != '\0')
			if (av[j][i++] == '-')
				sign = -1;
		while (av[j][i] && ft_isdigit(av[j][i]))
		{
			if (ft_in_int_range(sign, tmp, av[j][i]) == 0)
				return (0);
			tmp = tmp * 10 + av[j][i++] - '0';
		}
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
	if (!av[0])
		return (0);
	if (!check_digit(av) || !has_dupes(av))
		return (0);
	return (1);
}
