/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:03:15 by jopedro-          #+#    #+#             */
/*   Updated: 2025/01/30 18:06:05 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft/libft.h"
# include "lib/libft/ft_printf/ft_printf.h"

typedef struct s_elem
{
	int				num;
	struct s_elem	*next;
	int				index;
}	t_elem;

int		check_digit(char **av);
int		has_dupes(char **av);
int		check_input(char **av);
t_elem	*crt_stack(char **av);
void	add_to_stack(t_elem **stack, int num);
int		is_ordered(t_elem *stack);
int		stack_size(t_elem *stack);
void	ra(t_elem **stack_a, int flag);
void	rb(t_elem **stack_b, int flag);
void	sa(t_elem **stack);
void	sb(t_elem **stack);
void	rr(t_elem **stack_a, t_elem **stacl_b);
void	rra(t_elem **stack);
void	rrb(t_elem **stack);
void	pb(t_elem **stack_a, t_elem **stack_b);
void	pa(t_elem **stacl_a, t_elem **stack_b);
void	assign_indices(t_elem *stack);
t_elem	*crt_elem(int value);
void	radix_sort(t_elem **stack_a, t_elem **stack_b, int size);
void	free_stack(t_elem *stack);
void	ext_error(t_elem *stack_a, t_elem *stack_b);
void	sort(t_elem **stack_a, t_elem **stack_b);
int		find_smallest(t_elem *stack);
int		find_second_smallest(t_elem *stack);
int		find_insert_position(t_elem *stack_a, int value);
t_elem	*find_max(t_elem *stack);
int		get_position(t_elem *stack, t_elem *target);
void	opt_sort(t_elem **stack_a, t_elem **stack_b, int size, int chunks);
void	sort_100(t_elem **stack_a, t_elem **stack_b, int size);
void	move_back_to_a(t_elem **stack_a, t_elem **stack_b);
void	sort_three(t_elem **stack_a);
void	sort_four(t_elem **stack_a, t_elem **stack_b);

#endif
