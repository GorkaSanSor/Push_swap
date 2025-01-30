/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:23 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/30 18:12:11 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	ft_sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	ft_sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

// sa and sb at the same time.
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	ft_printf("ss\n");
}
