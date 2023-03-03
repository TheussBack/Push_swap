/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:45:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/03 05:40:24 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	long long int	content;
	struct s_list *next;
	int	index;
}					t_list;

//actions

void	sa(t_list **a_stack);
void	sb(t_list **b_stack);
void	ss(t_list **a_stack, t_list **b_stack);
void	ra(t_list **a_stack);
void	rb(t_list **b_stack);

//actions2

void	rr(t_list **a_stack, t_list **b_stack);
void	rra(t_list **a_stack);
void	rrb(t_list **b_stack);
void	rrr(t_list **a_stack, t_list **b_stack);

//push

void	pa(t_list **a_stack, t_list **b_stack);
void	pb(t_list **a_stack, t_list **b_stack);

//parsing

int	ft_parse(int ac, char **av);
void    print_stacks(t_list *a_stack, t_list *b_stack);
t_list	*ft_fill(t_list **a_stack, char **arg_cpy, int nb_arg, int i);

//utils

void	ft_add_back(t_list **lst, t_list *new);
t_list	*ft_new_lst(long long int content);
int	ft_atoi_overflow(const char *nptr, int *code_error);
t_list	*ft_lstlast(t_list *lst);
int	is_digit(char *av);

//utils2

int	ft_count_args(char *str, char c);
int	ft_manage_error(long long int nb);


//split

int	is_charset(char c, char *charset);
int	wordcount(char *str, char *charset);
char	*get_word(char *str, char *charset, int index);
char	**split(char *str, char *charset);


//exit

void	ft_putstr_fd(char *s, int fd);
void	exit_fail(char *str);
int	is_double(char **av, int nb, int i);
void	free_tab(char **tab);

//sort_3

void	sort_3(t_list **a_stack);
int	find_highest_index(t_list *stack);
void	sort_2(t_list **a_stack);

//sort

void	ft_sort(t_list **a_stack, t_list **b_stack, int stack_size);
int	is_sorted(t_list *stack);
int	get_stack_size(t_list	*stack);

//get index

void	ft_set_index(t_list **stack);
t_list	*ft_get_next_min(t_list **stack);

#endif
