/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/24 13:21:24 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Necesaria solo para testeo
void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Number: %d\n", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

// Checkea la cantidad de numeros y llama al algoritmo correspondiente.
static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int split_count)
{
	if (split_count < 2)
		return;
	else if (split_count == 2 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sa(stack_a);
	else if (split_count == 3 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sort_three(stack_a);
	else if (split_count == 4 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sort_four(stack_a, stack_b);
//	else if (split_count == 5 && ft_stack_is_sorted(*stack_a) == 0)
//		ft_sort_five(stack_a, stack_b);
	else
		ft_sort(stack_a);
}

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_utils utils;

	ft_check_errors(argc, argv, &utils, &stack_a);

	ft_push_swap(&stack_a, &stack_b, ft_split_count(utils.split));

	ft_printf("Stack A:\n");
	ft_print_stack(stack_a);
	ft_printf("Stack B:\n");
	ft_print_stack(stack_b);
	
	ft_free_all(&stack_a, &stack_b, &utils);

	return (0);
}

