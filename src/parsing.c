/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:30:36 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/22 21:32:35 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_list(int ac, char **av, t_list **list_a)
{
	t_list	*new;
	int i;
	(void)ac;

	i = 1;
	if (ac == 2)
	{
		av = split(av[1], " ");
		i = 0;
	}

	while (av[i])
	{
		if (is_digit(av[i]))
			exit_fail("On veut que des digit trouduc\n");
		if (is_double(av[i], i))
			exit_fail("Y'a un double");
		new = ft_new_lst(ft_atoi(av[i]));
		ft_add_back(list_a, new);
		if (!(new->content >= INT_MIN && new->content <= INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

int main (int ac, char **av)
{
	t_list	*list_a;

	list_a = NULL;
	if (ft_new_list(ac, av, &list_a))
		return (1);
	// cpy = list_a;
	while (list_a)
	{
		printf("%lld\n", list_a->content);
		list_a = list_a->next;
	}
}
