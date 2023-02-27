/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uttils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:54:44 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/27 19:36:19 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *av)
{
	int	i;

	i = -1;
	if (av[0] == '-')
		i = 0;
	while (av[++i])
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
	return (0);
}

int	ft_manage_error(long long int nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (1);
	else
		return (0);
}

int	ft_count_args(char *str, char c)
{
	int	trigger;
	int	count;
	int	n;

	trigger = 1;
	n = 0;
	count = 0;
	while (str[n])
	{
		if (str[n] != c)
		{
			if (trigger)
				count++;
			trigger = 0;
		}
		else
			trigger = 1;
		n++;
	}
	return (count);
}

t_list	*ft_fill(t_list **a_stack, char **arg_cpy, int nb_arg, int i)
{
	t_list	*new_cpy;

	while (i < nb_arg)
	{
		new_cpy = ft_new_lst(atoi(arg_cpy[i]));
		ft_add_back(a_stack, new_cpy);
		i++;
	}
	return (*a_stack);
}
