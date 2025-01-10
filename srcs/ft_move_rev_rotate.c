/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:44:20 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 13:36:04 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements of the stack down one position. 
// The last element becomes the first.
static void	ft_rev_rotate(t_stack **head)
{
    t_stack *current;
    t_stack *prev;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    current = *head;
    prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *head;
    *head = current;
}

void	ft_rra(t_stack **head_a)
{
    ft_rev_rotate(head_a);
    ft_printf("rra\n");
}
void	ft_rrb(t_stack **head_b)
{
    ft_rev_rotate(head_b);
    ft_printf("rrb\n");
}
void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
    ft_rev_rotate(head_a);
    ft_rev_rotate(head_b);
    ft_printf("rrr\n");
}