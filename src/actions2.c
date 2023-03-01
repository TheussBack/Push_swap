/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:58:50 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/01 18:41:58 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a_stack, t_list **b_stack)
{
	ra(a_stack);
	rb(b_stack);
	write(1, "rr\n", 3);
}

void	rra(t_list **a_stack)
{
	t_list	*tmp;
	t_list	*cp;

	tmp = NULL;
	cp = NULL;
	if (!(*a_stack) || !((*a_stack)->next))
		return ;
	tmp = *a_stack;
	cp = *a_stack;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp =cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *a_stack;
	*a_stack = tmp;
	write (1, "rra\n", 4);
}

void	rrb(t_list **b_stack)
{
	t_list	*tmp;
	t_list	*cp;

	tmp = NULL;
	cp = NULL;
	if (!(*b_stack) || !((*b_stack)->next))
		return ;
	tmp = *b_stack;
	cp = *b_stack;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp =cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *b_stack;
	*b_stack = tmp;
	write (1, "rra\n", 4);
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	rra(a_stack);
	rrb(b_stack);
	write (1,"rrr\n", 4);
}

