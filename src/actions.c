/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:28:50 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/28 19:22:27 by hrobin           ###   ########.fr       */
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
}

void	sb(t_list **b_stack)
{
	int tmp;

	tmp = 0;
	tmp = (*b_stack)->content;
	(*b_stack)->content = (*b_stack)->next->content;
	(*b_stack)->next->content = tmp;
}

void	ss(t_list **a_stack, t_list **b_stack)
{
	int tmp;

	tmp = 0;
	tmp = (*a_stack)->content;
	(*a_stack)->content = (*a_stack)->next->content;
	(*a_stack)->next->content = tmp;
	tmp = 0;
	tmp = (*b_stack)->content;
	(*b_stack)->content = (*b_stack)->next->content;
	(*b_stack)->next->content = tmp;
}
