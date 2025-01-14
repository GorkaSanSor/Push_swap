/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:29:35 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Necesaria solo para testeo
static void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Number: %d\n", stack->number);
		stack = stack->next;
	}
}

// Checkea la cantidad de numeros y llama al algoritmo correspondiente.
static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int word_count)
{
	if (word_count < 2)
		return;
	else if (word_count == 2 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sa(stack_a);
	else if (word_count == 3 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sort_three(stack_a);
	else if (word_count == 4 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sort_four(stack_a, stack_b);
	else if (word_count == 5 && ft_stack_is_sorted(*stack_a) == 0)
		ft_sort_five(stack_a, stack_b);
	else
		ft_printf("Trabajando para ordenar más de 5 numeros\n");
}

int main(int argc, char **argv) {
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_utils utils;

	ft_errors(argc, argv, &utils, &stack_a);

	ft_push_swap(&stack_a, &stack_b, ft_split_count(utils.split));

	ft_print_stack(stack_a);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	ft_free_utils(&utils);

	return 0;
}

