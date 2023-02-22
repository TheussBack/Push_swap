/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:38 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/22 21:33:23 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double(char *av, int i)
{
	int	j;

	j = i;
	j--;
	while (av[j] < 0)
	{
		if (av[i] == av[j--])
			return(1);
	}
	return(0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}

void	exit_fail(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
