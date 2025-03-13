/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:22 by jopedro-          #+#    #+#             */
/*   Updated: 2025/03/11 15:27:02 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_elem	*stack_a;
	t_elem	*stack_b;

	if (ac < 2)
		exit(1);
	++av;
	if (ac == 2)
		av = ft_split(av[0], ' ');
	if (!check_input(av))
	{
		if (ac == 2)
			free_split(av);
		ext_error(NULL, NULL, NULL);
	}
	stack_a = crt_stack(av);
	stack_b = NULL;
	if (!is_ordered(stack_a))
		sort(&stack_a, &stack_b);
	if (ac == 2)
		free_split(av);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
