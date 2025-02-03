/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:44:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/31 12:29:44 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements of the stack down, moving the last to the first.
static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	if (prev != NULL)
		prev->next = NULL;
}

// The last element of a becomes the first one.
void	ft_rra(t_stack **a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

// The last element of b becomes the first one.
void	ft_rrb(t_stack **b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}

// rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}
