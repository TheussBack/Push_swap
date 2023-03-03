/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 05:32:45 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/03 05:45:43 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort(t_list **a_stack, t_list **b_stack, int stack_size)
{
	(void)b_stack;
	if (stack_size == 2 && !is_sorted(*a_stack))
		sa(a_stack);
	else if (stack_size == 3)
		sort_3(a_stack);
	// else if (stack_size > 3 && !is_sorted(*a_stack))
	// 	sort(a_stack, b_stack);
}
