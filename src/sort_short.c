/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:48:49 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/09 23:25:10 by marvin           ###   ########.fr       */
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

int	ft_get_index_min(t_list **stack, int val)
{
	t_list	*stack_cpy;
	int		index_min;

	stack_cpy = *stack;
	index_min = stack_cpy->index;
	while (stack_cpy->next)
	{
		stack_cpy = stack_cpy->next;
		if ((stack_cpy->index < index_min) && stack_cpy->index != val)
			index_min = stack_cpy->index;
	}
	return (index_min);
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

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min_position;

	min_position = ft_find_min_position(stack_a, ft_get_index_min(stack_a, -1));
	if (min_position == 1)
		ra(stack_a);
	else if (min_position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_position == 3)
		rra(stack_a);
	if (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
	}
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_position;

	(void)stack_b;
	min_position = ft_find_min_position(stack_a, ft_get_index_min(stack_a, -1));
	if (min_position == 1)
		ra(stack_a);
	else if (min_position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (min_position == 4)
		rra(stack_a);
	if (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort_4(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}