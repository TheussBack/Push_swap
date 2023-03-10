/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:30:36 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/09 23:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_add_back(t_list **lst, t_list *new)
{
	t_list	*blabla;

	if (lst == NULL || new == NULL)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		blabla = ft_lstlast(*lst);
		blabla->next = new;
	}
}
t_list	*ft_new_lst(long long int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_fill_stack(int ac, char **av)
{
	t_list	*a_stack;
	char *my_args;
	char **arg_cpy;
	int	nb_arg;
	int	i;

	i = 0;
	a_stack = NULL;
	if (ac == 2)
	{
		my_args = strdup(av[1]);
		arg_cpy = split(my_args, " ");
		// free (my_args);
		nb_arg = ft_count_args(av[1], ' ');
		i = 0;
	}
	else
	{
		i = 1;
		arg_cpy = av;
		nb_arg = ac;
	}
	a_stack = ft_fill(&a_stack, arg_cpy, nb_arg, i);
	//ft_se|_index
	//free my args (le doubl ab)
	return (a_stack);
}

int	ft_parse(int ac, char **av)
{
	int i;
	(void)ac;
	int	error_code;
	int	to_check;

	i = 1;
	error_code = 0;
	if (ac == 2)
	{
		av = split(av[1], " ");
		i = 0;
	}
	while (av[i])
	{
		to_check = ft_atoi_overflow(av[i], &error_code);
		(void)to_check;
		if (error_code == 1)
		{
			printf("Overflow");
			return (1);
		}
		if (is_digit(av[i]))
		{
			printf("On veut que des digit trouduc\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (av[i])
	{
		if (is_double(av, atoi(av[i]), i))
			exit_parse("Double");
		i++;
	}
	// free_tab(av);
	return (0);
}