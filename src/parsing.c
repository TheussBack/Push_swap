/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:30:36 by hrobin            #+#    #+#             */
/*   Updated: 2023/03/01 19:18:47 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			exit_fail("Double");
		i++;
	}
	free_tab(av);
	return (0);
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
		free (my_args);
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

// void    ft_print_one_stack(t_list *stack, char stack_name)
// {
//     t_list    *stack_cpy;

//     stack_cpy = stack;
//     printf("%c_stack\n", stack_name);
//     while (stack_cpy != NULL)
//     {
//     	printf("%lld\n", stack_cpy->content);
//         stack_cpy = stack_cpy->next;
//     }
// }

void    print_stacks(t_list *a_stack, t_list *b_stack)
{
    printf("__________________________________________");
    printf("________________________________________\t\t\t\n\n");
    printf("a_stack\t\t\tb_stack\n");
    while (a_stack != NULL || b_stack != NULL)
    {
        if (a_stack != NULL)
        {
            printf("%lld\t\t\t", a_stack->content);
            a_stack = a_stack->next;
        }
        else
            printf("\t\t\t\t\t\t");
        if (b_stack != NULL)
        {
            printf("%lld\t\t\t", b_stack->content);
            b_stack = b_stack->next;
        }
        else
            printf("\t\t\t\t\t\t");
        printf("\n");
    }
    printf("__________________________________________");
    printf("________________________________________\t\t\t\n\n");
}


int main (int ac, char **av)
{
	t_list	*stack_a;
	// int	i;
	t_list	*stack_b;
	// i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_parse(ac, av))
		exit_fail("Error");
	stack_a = ft_fill_stack(ac, av);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	sa(&stack_a);
	pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);

	return (0);
	// while (stack_a)
	// {
	// 	printf("%lld\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
}
