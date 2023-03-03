/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:38:51 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/03 04:52:09 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// trouve la valeur min de la stack qui n'a pas encore d'index et la retourne
// l'index est mis a -1 par defaut si il n'a pas encore ete definit
t_list	*ft_get_next_min(t_list **stack)
{
	t_list	*first_elem_stack;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	first_elem_stack = *stack;
	if (first_elem_stack)
	{
		while (first_elem_stack)
		{
			if ((first_elem_stack->index == -1) && (!has_min
					|| first_elem_stack->content < min->content))
			{
				min = first_elem_stack;
				has_min = 1;
			}
			first_elem_stack = first_elem_stack->next;
		}
	}
	return (min);
}

// definit l'index de chaque element de la stack
void	ft_set_index(t_list **stack)
{
	t_list	*first_elem_stack;
	int		index;

	index = 0;
	first_elem_stack = ft_get_next_min(stack);
	while (first_elem_stack)
	{
		first_elem_stack->index = index++;
		first_elem_stack = ft_get_next_min(stack);
	}
}
