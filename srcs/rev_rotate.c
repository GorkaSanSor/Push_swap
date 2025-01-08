/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:44:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/08 14:13:52 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements of the stack down one position. the stack a. 
// The last element becomes the first.
static void	ft_rev_rotate(t_stack **head)
{
    t_stack *current;
    t_stack *prev;

    if (*head == NULL || (*head)->ptr_to_next == NULL)
        return ;
    current = *head;
    prev = NULL;
    while (current->ptr_to_next != NULL)
    {
        prev = current;
        current = current->ptr_to_next;
    }
    prev->ptr_to_next = NULL;
    current->ptr_to_next = *head;
    *head = current;
}

void	ft_rra(t_stack **head_a)
{
    ft_rev_rotate(head_a);
}
void	ft_rrb(t_stack **head_b)
{
    ft_rev_rotate(head_b);
}
void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
    ft_rev_rotate(head_a);
    ft_rev_rotate(head_b);
}