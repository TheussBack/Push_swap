/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:45:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/27 19:17:56 by hrobin           ###   ########.fr       */
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

int	ft_parse(int ac, char **av);

//utils

void	ft_add_back(t_list **lst, t_list *new);
t_list	*ft_new_lst(long long int content);
int	ft_atoi_overflow(const char *nptr, int *code_error);
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
int	is_double(char **av, int nb, int i);

//plus

t_list	*ft_fill(t_list **a_stack, char **arg_cpy, int nb_arg, int i);
int	ft_count_args(char *str, char c);
int	ft_manage_error(long long int nb);

#endif
