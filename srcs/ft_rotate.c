/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:19:18 by gsantill          #+#    #+#             */
/*   Updated: 2025/01/10 13:11:55 by gsantill         ###   ########.fr       */
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
	while (current->next != NULL)
		current = current->next;
	current->next = lsthead;
	*head = lsthead->next;
	lsthead->next = NULL;
}

void	ft_ra(t_stack **head_a)
{
	ft_rotate(head_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **head_b)
{
	ft_rotate(head_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	ft_printf("rr\n");
}