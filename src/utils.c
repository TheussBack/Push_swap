/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:19:51 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/27 18:55:03 by hrobin           ###   ########.fr       */
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
	new->next = NULL;
	return (new);
}

int	ft_atoi_overflow(const char *nptr, int *error_code)
{
	size_t	i;
	int		sign;
	long long int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	*error_code = ft_manage_error(sign * result);
	return (sign * result);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
