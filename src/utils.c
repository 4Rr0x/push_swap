/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:58:05 by jopedro-          #+#    #+#             */
/*   Updated: 2025/03/11 15:25:23 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_in_int_range(int sign, int nbr, char c)
{
	if (nbr * sign > INT_MAX / 10 || nbr * sign < INT_MIN / 10)
		return (0);
	if ((nbr * sign == INT_MAX / 10 && c - '0' > INT_MAX % 10) || (nbr
			* sign == INT_MIN / 10 && c - '0' > -(INT_MIN % 10)))
		return (0);
	return (1);
}

void	free_split(char **strs)
{
	size_t	i;

	if (strs == NULL || *strs == NULL)
		return ;
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}
