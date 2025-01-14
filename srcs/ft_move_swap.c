/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:23 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:32:24 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack *current;
	t_stack *temp;

	current = *stack;
	temp = current->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = temp->next;
	(*stack)->next = current;
	temp->next = *stack;
	*stack = temp;
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

// sa and sb at the same time.
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("ss\n");
}
