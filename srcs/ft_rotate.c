/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:18 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/08 13:48:42 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all the elements of the stack a up by one position. 
// The first element becomes the last. 
static void	ft_rotate(t_stack **head)
{
	t_stack *current;
	t_stack *lsthead;

	lsthead = *head;
	current = *head;
	while (current->ptr_to_next != NULL)
		current = current->ptr_to_next;
	current->ptr_to_next = lsthead;
	*head = lsthead->ptr_to_next;
	lsthead->ptr_to_next = NULL;
}

void	ft_ra(t_stack **head_a)
{
	ft_rotate(head_a);
}

void	ft_rb(t_stack **head_b)
{
	ft_rotate(head_b);
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}