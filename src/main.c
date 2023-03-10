/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:24:03 by marvin            #+#    #+#             */
/*   Updated: 2023/03/09 20:24:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    print_stacks(t_list *a_stack, t_list *b_stack)
{
    printf("__________________________________________");
    printf("________________________________________\t\t\t\n\n");
    printf("index\t\t\ta_stack\t\t\tindex\t\t\tb_stack\n");
    while (a_stack != NULL || b_stack != NULL)
    {
        if (a_stack != NULL)
        {
			printf("%d\t\t\t", a_stack->index);
            printf("%lld\t\t\t", a_stack->content);
            a_stack = a_stack->next;
        }
        else
            printf("\t\t\t\t\t\t");
        if (b_stack != NULL)
        {
			printf("%d\t\t\t", b_stack->index);
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
	t_list	*stack_b;
	int	stack_size;

	stack_size = 0;
	stack_a = NULL;
	stack_b = NULL;
    if (ac >= 2)
    {
	    if (ft_parse(ac, av))
		    ft_exit("Error", &stack_a, &stack_b);
	    stack_a = ft_fill_stack(ac, av);
	    ft_set_index(&stack_a);
	    stack_size = get_stack_size(stack_a);
        if (is_sorted(stack_a))
        {
            ft_exit("Error", &stack_a, &stack_b);
        }
	    ft_sort(&stack_a, &stack_b, stack_size);
	    print_stacks(stack_a, stack_b);
	    lst_destroy(stack_a);
	    lst_destroy(stack_b);
    }
	return (0);
}