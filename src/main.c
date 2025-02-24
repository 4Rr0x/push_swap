/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:35:22 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 17:44:12 by jopedro-         ###   ########.fr       */
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
		ext_error(NULL, NULL);
	stack_a = crt_stack(av);
	if (is_ordered(stack_a))
		return (0);
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
