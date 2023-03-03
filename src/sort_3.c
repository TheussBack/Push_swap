/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:48:49 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/03 05:37:47 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_list *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}


void	sort_3(t_list **a_stack)
{
	int		highest;

	highest = find_highest_index(*a_stack);
	if ((*a_stack)->index == highest)
		ra(a_stack);
	else if ((*a_stack)->next->index == highest)
		rra(a_stack);
	if ((*a_stack)->index > (*a_stack)->next->index)
		sa(a_stack);
}
