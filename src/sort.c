/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 05:32:45 by hrobin            #+#    #+#             */
/* 	  Updated: 2023/03/09 22:36:24 by marvin           ###   ########.fr       */
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

void	ft_sort_mini(t_list **a_stack, t_list **b_stack)
{
	int	size;
	
	if (is_sorted(*a_stack) || get_stack_size(*a_stack) <= 1)
		return ;
	size = get_stack_size(*a_stack);
	if (size == 2)
		sa(a_stack);
	else if (size == 3)
		sort_3(a_stack);
	else if (size == 4)
		ft_sort_4(a_stack, b_stack);
	else if (size == 5)
		ft_sort_5(a_stack, b_stack);
	
}

int	ft_find_min_position(t_list **a_stack, int index_min)
{
	t_list	*stack_cpy;
	int		dist;

	stack_cpy = *a_stack;
	dist = 0;
	while (stack_cpy)
	{
		if (stack_cpy->index == index_min)
			break ;
		stack_cpy = stack_cpy->next;
		dist++;
	}
	return (dist);
}

void	ft_sort(t_list **a_stack, t_list **b_stack, int stack_size)
{
	if (stack_size <= 5)
		ft_sort_mini(a_stack, b_stack);
	// else
	// 	ft_radix_sort(a_stack, b_stack);
	// ft_exit("done", a_stack, b_stack);
// 	(void)b_stack;
// 	if (stack_size == 2 && !is_sorted(*a_stack))
// 		sa(a_stack);
// 	else if (stack_size == 3)
// 		sort_3(a_stack);
} 