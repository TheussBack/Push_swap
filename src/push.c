/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:27:01 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/01 19:09:05 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (!(*b_stack))
		return ;
	tmp = *b_stack;
	*b_stack = (*b_stack)->next;
	tmp->next = *a_stack;
	*a_stack = tmp;
	write (1, "pa\n", 3);
}

void	pb(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (!(*a_stack))
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = *b_stack;
	*b_stack = tmp;
	write (1, "pb\n", 3);
}
