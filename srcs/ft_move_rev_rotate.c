/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:44:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/14 12:32:01 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements of the stack down one position. 
// The last element becomes the first.
static void	ft_rev_rotate(t_stack **stack)
{
    t_stack *current;
    t_stack *prev;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    current = *stack;
    prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

void	ft_rra(t_stack **stack_a)
{
    ft_rev_rotate(stack_a);
    ft_printf("rra\n");
}
void	ft_rrb(t_stack **stack_b)
{
    ft_rev_rotate(stack_b);
    ft_printf("rrb\n");
}
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rev_rotate(stack_a);
    ft_rev_rotate(stack_b);
    ft_printf("rrr\n");
}