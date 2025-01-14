/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:18 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:32:13 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all the elements of the stack a up by one position. 
// The first element becomes the last. 
static void	ft_rotate(t_stack **stack)
{
	t_stack *current;
	t_stack *lststack;

	lststack = *stack;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = lststack;
	*stack = lststack->next;
	lststack->next = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}