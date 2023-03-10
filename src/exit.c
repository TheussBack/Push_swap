/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:38 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/09 23:34:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_parse(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

int	is_double(char **av, int nb, int i)
{
	i++;
	while (av[i])
	{
		if (atoi(av[i]) == nb)
			return(1);
		i++;
	}
	return(0);
}

void	ft_exit(char *str, t_list **a_stack, t_list **b_stack)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
	exit(EXIT_FAILURE);
}

void	lst_destroy(t_list *list)
{
	if (list == NULL)
		return ;
	lst_destroy(list->next);
	if (list->next != NULL)
		free(list->next);
	free(list);
}
