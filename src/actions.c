/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:28:50 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/01 18:18:28 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a_stack)
{
	int tmp;

	tmp = 0;
	tmp = (*a_stack)->content;
	(*a_stack)->content = (*a_stack)->next->content;
	(*a_stack)->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **b_stack)
{
	int tmp;

	tmp = 0;
	tmp = (*b_stack)->content;
	(*b_stack)->content = (*b_stack)->next->content;
	(*b_stack)->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **a_stack, t_list **b_stack)
{
	sa(a_stack);
	sb(b_stack);
	write(1, "ss\n", 3);
}

void	ra(t_list **a_stack)
{
	t_list	*tmp;
	t_list	*cp;

	tmp = NULL;
	cp = NULL;
	if (!(*a_stack) || !((*a_stack)->next))
		return ;
	tmp = *a_stack;
	cp = (*a_stack)->next;
	while ((*a_stack)->next)
		*a_stack = (*a_stack)->next;
	(*a_stack)->next = tmp;
	tmp->next = NULL;
	*a_stack = cp;
	write(1, "ra\n", 3);
}

void	rb(t_list **b_stack)
{
	t_list	*tmp;
	t_list	*cp;

	tmp = NULL;
	cp = NULL;
	if (!(*b_stack) || !((*b_stack)->next))
		return ;
	tmp = *b_stack;
	cp = (*b_stack)->next;
	while ((*b_stack)->next)
		*b_stack = (*b_stack)->next;
	(*b_stack)->next = tmp;
	tmp->next = NULL;
	*b_stack = cp;
	write(1, "ra\n", 3);
}
