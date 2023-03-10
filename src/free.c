/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:34:40 by marvin            #+#    #+#             */
/*   Updated: 2023/03/09 20:34:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **stack)
{
	t_list	*stack_copy;
	t_list	*tmp;

	stack_copy = *stack;
	while (stack_copy)
	{
		tmp = stack_copy;
		stack_copy = stack_copy->next;
		free(tmp);
	}
}

void	ft_free_args(char **my_args, int ac)
{
	int	i;

	if (ac != 2)
		return ;
	i = 0;
	while (my_args[i])
	{
		free(my_args[i]);
		i++;
	}
	free(my_args);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}