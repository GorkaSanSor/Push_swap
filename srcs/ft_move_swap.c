/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:23 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:18:33 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first two elements of the stack.
static void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

// Swaps the first two elements of stack a and prints "sa".
void	ft_sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

// Swaps the first two elements of stack b and prints "sb".
void	ft_sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

// Performs sa and sb at the same time and prints "ss".
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_printf("ss\n");
}
