/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:39:12 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:25:40 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
static void	ft_push_swap(t_stack **a, t_stack **b, int split_count)
{
	if (split_count < 2)
		return ;
	else if (split_count == 2 && ft_stack_is_sorted(*a) == 0)
		ft_sa(a);
	else if (split_count == 3 && ft_stack_is_sorted(*a) == 0)
		ft_sort_three(a);
	else if (split_count == 4 && ft_stack_is_sorted(*a) == 0)
		ft_sort_four(a, b);
	else
		ft_sort_big(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_utils	utils;

	a = NULL;
	b = NULL;
	ft_check_errors(argc, argv, &utils, &a);
	ft_push_swap(&a, &b, ft_split_count(utils.split));
	ft_printf("Stack A:\n");
	ft_print_stack(a);
	ft_printf("Stack B:\n");
	ft_print_stack(b);
	ft_free_all(&a, &b, &utils);
	return (0);
}
