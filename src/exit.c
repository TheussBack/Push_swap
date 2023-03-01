/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:31:38 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/01 16:38:52 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
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
