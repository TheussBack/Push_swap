/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:45:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/22 21:33:02 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	long long int	content;
	struct s_list *next;
}					t_list;

//parsing

int	ft_new_list(int ac, char **av, t_list **stack_a);

//utils

void	ft_add_back(t_list **lst, t_list *new);
t_list	*ft_new_lst(long long int content);
int	ft_atoi(const char *nptr);
t_list	*ft_lstlast(t_list *lst);
int	is_digit(char *av);

//split

int	is_charset(char c, char *charset);
int	wordcount(char *str, char *charset);
char	*get_word(char *str, char *charset, int index);
char	**split(char *str, char *charset);

//exit

void	ft_putstr_fd(char *s, int fd);
void	exit_fail(char *str);
int	is_double(char *av, int i);

#endif
